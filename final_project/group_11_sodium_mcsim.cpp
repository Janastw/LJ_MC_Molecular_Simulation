#include <iostream>
#include <cmath>
#include <random> // From random_number_generator
#include <chrono> // From random_number_generator for generating random seeds
#include <fstream> // From read_xyz, for reading and writing files
#include <array> // From read_xyz, for std::array
#include <vector> // From read_xyz, for std::vector
#include <utility> // From read_xyz, for std::pair

// Make some types more convenient
typedef std::array<double, 3> AtomCoord; // From read_xyz
typedef std::vector<AtomCoord> Coordinates; // From read_xyz


std::default_random_engine re; // A Global! Probably shouldn't be used in real code - for Random Number Generator
std::pair<Coordinates, double> read_xyz(std::string file_path); // From read_xyz


double calculate_LJ(double r_ij);
bool accept_or_reject(double delta_e, double beta);
double random_double(double lower_bound, double upper_bound);
int random_integer(int lower_bound, int upper_bound);
double calculate_tail_correction(int n_particles, double box_length, double cutoff);
double calculate_pair_energy(const Coordinates & coordinates, int i_particle, double box_length, double cutoff);
double calculate_distance(const AtomCoord & coord1, const AtomCoord & coord2, double box_length);
double calculate_total_energy(const Coordinates & coordinates, double box_length, double cutoff);
std::pair<std::vector<double>, std::vector<double> > run_simulation(Coordinates coordinates, double box_length, double cutoff, double reduced_temperature, int num_steps, double max_displacement = 0.1, int freq = 1000);





int main(void)
{
    // Initialize random number generation based on time
    re.seed(std::chrono::system_clock::now().time_since_epoch().count());

    // From read_xyz
    std::pair<Coordinates, double> xyz_info = read_xyz("../data/sample_config1.txt");

    // Arguments for run_simulation function
    Coordinates coords = xyz_info.first;
    double box_length = xyz_info.second;
    double reduced_temperature = 0.9;
    int num_steps = 50000;
    double cutoff = 3;
    double max_displacement = 0.1;
    int freq = 1000;
    
    run_simulation(coords, box_length, cutoff, reduced_temperature, num_steps, max_displacement, freq);

    return 0;
}

double calculate_LJ(double r_ij)
{
    // calculate pairwise_energy using the Lennard Jones equation
    double r6_term = pow(1.0 / r_ij, 6);
    double r12_term = pow(r6_term, 2);
    double pairwise_energy = 4 * (r12_term - r6_term);
    return pairwise_energy;
}

double calculate_distance(const AtomCoord & coord1, const AtomCoord & coord2, double box_length)
{
    // calculate the distance between two particles in 3D space
    double distance = 0;
    for(int i=0; i < 3; i++)
    {
        double dim_dist = coord1[i] - coord2[i];
        if(box_length)
        {
            dim_dist = dim_dist - box_length * round(dim_dist / box_length);
        }
        dim_dist = pow(dim_dist, 2);
        distance += dim_dist;
    }
    distance = pow(distance, 0.5);
    return distance;
}

double calculate_total_energy(const Coordinates & coordinates, double box_length, double cutoff)
{
    // calculate the total energy of a system of particles
    double total_energy = 0;

    // determine the number of particles in the systm
    int num_atoms = coordinates.size();

    // iterate over all pairs and calculate distances
    for(int i = 0; i < num_atoms; i++)
    {
        for(int j = i + 1; j<num_atoms; j++)
        {
            double dist_ij = calculate_distance(coordinates[i], coordinates[j], box_length=box_length);

            // only add to the total energy if the distance is below the cutoff threshold
            if(dist_ij < cutoff)
            {
                double interaction_energy = calculate_LJ(dist_ij);
                total_energy += interaction_energy;
            }
        }
    }
    return total_energy;
}

double calculate_tail_correction(int n_particles, double box_length, double cutoff)
{
    // Calculat the tail correction of the system
    double volume_of_box = pow(box_length, 3);
    double rc3_term = pow(1/cutoff, 3);
    double rc9_term = pow(rc3_term, 3);
    double inside_term = (((1.0/3.0) * rc9_term) - rc3_term);
    double U_lrc = (8.0 * 2.0 * asin(1.0) * pow(n_particles, 2) / (3.0 * volume_of_box)) * inside_term;
    
    return U_lrc;
}

bool accept_or_reject(double delta_e, double beta)
{
    /*
    Accept or reject based on an energy and beta (inverse temperature) measurement.

    Parameters
    ----------
    delta_e: double
        An energy change in reduced units.
    beta: double
        Inverse temperature
    
    Returns
    -------
    bool
        True to accept move, False to reject
    */
   bool accept;
   if (delta_e <= 0.0)
   {
        accept = true;
   }
   else
   {
        double random_number = random_double(0, 1);// USE RANDOM
        double p_acc = std::exp(-delta_e * beta);

        if (random_number < p_acc)
        {
            accept = true;
        }
        else
        {
            accept = false;
        }
   }
   return accept;
}

double calculate_pair_energy(const Coordinates & coordinates, int i_particle, double box_length, double cutoff)
{
    double e_total = 0;
    const AtomCoord & i_position = coordinates[i_particle];
    int num_atoms = coordinates.size();
   
    for (int j_particle = 0; j_particle < num_atoms; j_particle++) {
        if (j_particle != i_particle){
            std::array<double, 3> j_position = coordinates[j_particle];
            double r_ij = calculate_distance(i_position, j_position, box_length);
            if (r_ij < cutoff){
                double e_pair = calculate_LJ(r_ij);
                e_total += e_pair;
            }
        }
    }
    return e_total;

}

std::pair<std::vector<double>, std::vector<double> > run_simulation(Coordinates coordinates, double box_length, double cutoff, double reduced_temperature, int num_steps, double max_displacement, int freq)
{
    double beta = 1 / reduced_temperature;
    int num_particles = coordinates.size();

    double total_energy = calculate_total_energy(coordinates, box_length, cutoff);
    total_energy += calculate_tail_correction(num_particles, box_length, cutoff);

    std::vector<double> steps; // Can possibly make a vector and use steps.push_back instead
    std::vector<double> energies; // Can possibly make a vector and use energies.push_back instead

    for (int step = 0; step < num_steps; step++)
    {
        // 1. Randomly pick one of N particles
        int random_particle = random_integer(0, num_particles);

        // 2. Calculate the interaction energy of the selected particle with the system
        double current_energy = calculate_pair_energy(coordinates, random_particle, box_length, cutoff);
        
        // 3. Generates a random x, y, z displacement
        double x_rand = random_double(0, 1);
        double y_rand = random_double(0, 1);
        double z_rand = random_double(0, 1);

        // 4. Modify the coordiante of Nth particle by the generated displacement.
        coordinates[random_particle][0] += x_rand;
        coordinates[random_particle][1] += y_rand;
        coordinates[random_particle][2] += z_rand;

        // 5. Calculate the interaction energy of the selected particle with the system and store this value (using the new position)
        double proposed_energy = calculate_pair_energy(coordinates, random_particle, box_length, cutoff);

        // 6. Calculate the change in energy and decide to accept or reject the change.
        double delta_e = proposed_energy - current_energy;

        bool accept = accept_or_reject(delta_e, beta);

        // 7. If accept, keep particle movement. If reject, move particle back.

        if (accept)
        {
            total_energy += delta_e;
        }
        else
        {
            // Move is not accepted, roll back coordinates
            coordinates[random_particle][0] -= x_rand;
            coordinates[random_particle][1] -= y_rand;
            coordinates[random_particle][2] -= z_rand;
        }

        // 8. Print the energy if the step is a multiple of freq
        if ((step % freq) == 0)
        {
            std::cout << step << ", " << total_energy / num_particles << std::endl;
            steps.push_back(step);
            energies.push_back(total_energy);
        }
    }
    return std::make_pair(steps, energies);
}

double random_double(double lower_bound, double upper_bound)
{
   std::uniform_real_distribution<double> dist(lower_bound, upper_bound);
   return dist(re);
}

int random_integer(int lower_bound, int upper_bound)
{           
   //dist will return [a,b] but we want [a,b)
   std::uniform_int_distribution<int> dist(lower_bound, upper_bound-1);
   return dist(re);
}

std::pair<Coordinates, double> read_xyz(std::string file_path)
{
    // Opens up a file stream for input
    std::ifstream infile(file_path);

    // Check that it was successfully opened
    if(!infile.is_open())
    {   
        throw std::runtime_error("File path in read_xyz does not exist!");
    }
    
    double dummy; // Data that is thrown away (box length, atom indices)
    double box_length;
    int num_atoms;
    
    // Grab box_length from first number, throw the rest away
    infile >> box_length >> dummy >> dummy;
    
    // now the number of atoms
    infile >> num_atoms;
    
    // Uncomment to help troubleshoot
    //std::cout << "Box length: " << box_length << " natoms: " << num_atoms << std::endl;
    
    // Stores the atomic coordinates
    // Remember, this is a vector of arrays
    Coordinates coords;
    
    for(int i = 0; i < num_atoms; i++)
    {   
        AtomCoord coord;
        
        // Throws away the atom index
        infile >> dummy >> coord[0] >> coord[1] >> coord[2];
        
        // Add to the vector
        coords.push_back(coord);
    }

    // Makes an appropriate pair object
    return std::make_pair(coords, box_length);
}