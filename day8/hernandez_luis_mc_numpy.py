import math
import random
import numpy as np

def calculate_distance(coord1, coord2, box_length=None):
    dim_dist = coord2 - coord1

    if box_length:
        dim_dist = dim_dist - box_length * np.round(dim_dist / box_length)
    
    if dim_dist.ndim < 2:
        dim_dist = dim_dist.reshape(1, -1)

    dim_dist_sq = dim_dist ** 2
    dim_dist_sum = dim_dist_sq.sum(axis=1)
    distance = np.sqrt(dim_dist_sum)

    return distance

def calculate_LJ(r_ij):
    """
    Calculate the Lennard Jones energy of a two particles given their distance from each other.

    Parameters
    ----------
    r_ij : np.array
        A numpy array consisting of distance between two particles.

    Returns
    -------
    pairwise_energy : np.array
        A numpy array consisting of pairwise energies.
    """
    r6_term = np.power(1/r_ij, 6)
    r12_term = np.power(r6_term, 2)
    pairwise_energy = 4 * (r12_term - r6_term)
    pairwise_energy
    return pairwise_energy

def calculate_total_energy(coordinates, box_length, cutoff):
    """
    Calculate the total Lennard Jones energy of a system of particles.

    Parameters
    ----------
    coordinates : list
        Nested list containing particle coordinates.

    Returns
    -------
    total_energy : float
        The total pairwise Lennard Jones energy of the system of particles.
    """
    total_energy = 0

    num_atoms = len(coordinates)
    copy_coordinates = coordinates[1:]

    all_distances = np.array([])
    short_list = np.array([])

    for i in range(num_atoms):
        dist_ij = calculate_distance(
            copy_coordinates, coordinates[i], box_length=box_length
        )
        all_distances = np.concatenate((all_distances, dist_ij), axis=0)
        copy_coordinates = copy_coordinates[1:]
            
    short_list = all_distances[(cutoff > all_distances)]
    short_list = short_list[(0 < short_list)]
    all_valid_energies = calculate_LJ(short_list)
    total_energy = all_valid_energies.sum(axis=0)

    return total_energy

def read_xyz(filepath):
    """
    Reads coordinates from an xyz file.
    
    Parameters
    ----------
    filepath : str
       The path to the xyz file to be processed.
       
    Returns
    -------
    atomic_coordinates : list
        A two dimensional list containing atomic coordinates

    """
    
    with open(filepath) as f:
        box_length = float(f.readline().split()[0])
        num_atoms = float(f.readline())
        coordinates = f.readlines()
    
    atomic_coordinates = []
    
    for atom in coordinates:
        split_atoms = atom.split()
        
        float_coords = []
        
        # We split this way to get rid of the atom label.
        for coord in split_atoms[1:]:
            float_coords.append(float(coord))
            
        atomic_coordinates.append(float_coords)
        
    
    return np.array(atomic_coordinates), box_length

def calculate_tail_correction(n_particles, box_length, cutoff):
    '''
    Calculates the tail correction to the internal energy found through the Lennard Jones Equation.
    
    Parameters
    ----------
    n_particles : int
        number of particles created for the simulation
    box_length : float
        length of the sides of the box created for the simulation
    cutoff : float
        cut-off distance
       
    Returns
    -------
    U_lrc : float
        this is the number corresponding with the energy of the particles outside of the defined cut-off limit    
    '''

    volume_of_box = math.pow((box_length),3)
    rc3_term = math.pow((1/cutoff),3)
    rc9_term = math.pow((rc3_term),3)
    inside_term = (((1/3)*rc9_term)-rc3_term)
    U_lrc = (8*math.pi*math.pow((n_particles),2)/(3*volume_of_box))*inside_term
    return U_lrc

def accept_or_reject(delta_e, beta):
    """Accept or reject based on an energy and beta (inverse temperature) measurement.
    
    Parameters
    ----------
    delta_e : float
        An energy change in reduced units
    beta: float
        Inverse temperature
        
    Returns
    -------
    bool
        True to accept move Flase to reject
    """
    if delta_e <= 0.0:
        accept = True
    else:
        random__number = random.random()
        p_acc = math.exp(-delta_e*beta)

        if random__number < p_acc:
            accept = True
        else:
            accept = False
    return accept

def calculate_pair_energy(coordinates, i_particle, box_length, cutoff):

    """
    Calculate the interaction energy of a particle with its environment (all other particles in the system).

    Parameters
    ----------
    coordinates: list
        The coordinates for all particles in the system
    i_particle: int
        The particle index for which to calculate the energy
    cutoff: float
        The simulation cutoff. Beyond this distance, the interactions are not calculated

    Returns
    -------
    e_total: float
        The pairwise interaction energy of the i_th particle with all other particles
    """
    e_total = 0.0
    i_position = coordinates[i_particle]
    
    # remove the particle of interest
    copy_coordinates = np.delete(coordinates, i_particle, 0)
    
    dist_ij = calculate_distance(
            copy_coordinates, i_position, box_length=box_length
        )
    # remove distances below cutoff
    short_list = dist_ij[(cutoff > dist_ij)]
    # calculate_LJ for distances
    all_valid_energies = calculate_LJ(short_list)
    # sum energies
    e_total = all_valid_energies.sum(axis=0)

    return e_total

# create a function called run_simulation that takes in simulation parameters and runs the simulation.
def run_simulation(coordinates, box_length, cutoff, reduced_temperature, num_steps, max_displacement=0.1, freq=1000):

    # # Simulation Parameters
    # reduced_temperature = 0.9
    # num_steps = 5000
    # max_displacement = 0.1
    # cutoff = 3.0

    # freq = 1000

    # Calculated quantities
    beta = 1 / reduced_temperature

    # # Get initial coordinates (initial system configuration)
    # coordinates, box_length = read_xyz("../data/sample_config1.txt")
    num_particles = len(coordinates)

    # delta_energy = 0

    total_energy = calculate_total_energy(coordinates, box_length, cutoff)
    total_energy += calculate_tail_correction(num_particles, box_length, cutoff)
    # print(total_energy)

    steps = []
    energies = []
    for step in range(num_steps):

        # 1. Randomly pick one of N particles
        random_particle = random.randrange(num_particles)

        # 2. Calculate the interaction energy of the selected particle with the system and store this value.
        current_energy = calculate_pair_energy(coordinates, random_particle, box_length, cutoff)
        # print(current_energy, step, random_particle)


        # 3. Generate a random x, y, z displacement
        x_rand = random.uniform(-max_displacement, max_displacement)
        y_rand = random.uniform(-max_displacement, max_displacement)
        z_rand = random.uniform(-max_displacement, max_displacement)

        # 4. Modify the coordinate of Nth particle by the generated displacements.
        coordinates[random_particle][0] += x_rand
        coordinates[random_particle][1] += y_rand
        coordinates[random_particle][2] += z_rand

        # 5. Calculate the interaction energy of the selected particle with the system and store this value (using the new position).
        proposed_energy = calculate_pair_energy(coordinates, random_particle, box_length, cutoff)
        # print(proposed_energy, step, random_particle)

        # 6. Calculate the change in energy and decide to accept or reject the change.
        delta_e = proposed_energy - current_energy

        accept = accept_or_reject(delta_e, beta)

        # 7. If accept, keep particle movement. If reject, move particle back.
        if accept:
            total_energy += delta_e
        else:
            # Move is not accepted, roll back coordinates
            coordinates[random_particle][0] -= x_rand
            coordinates[random_particle][1] -= y_rand
            coordinates[random_particle][2] -= z_rand

        # 8. Print the energy if the step is a multiple of freq
        if step % freq == 0:
            print (step, total_energy/num_particles)
            steps.append(step)
            energies.append(total_energy/num_particles)
    return steps, energies

# config_file1 = "../data/sample_config1.txt"

# coords, box_length = read_xyz(config_file1)

# run_simulation(coords, box_length, 3, 0.9, 2500, max_displacement=0.1, freq=1000)
