"""
Python Standard Library Implementation of MC simulation code.
"""
import math
import random

def calculate_LJ(r_ij):
    """
    Calculate the Lennard Jones energy of a two particles given their distance from each other.

    Parameters
    ----------
    r_ij : float
        A distance between two particles.

    Returns
    -------
    pairwise_energy : float
        The pairwise energy between two particles.
    """
    r6_term = math.pow(1/r_ij, 6)
    r12_term = math.pow(r6_term, 2)
    pairwise_energy = 4 * (r12_term - r6_term)
    return pairwise_energy

def calculate_distance(coord1, coord2, box_length=None):
    """
    Calculate the distance between two 3D coordinates.

    Parameters
    ----------
    coord1, coord2: list
        The atomic coordinates

    Returns
    -------
    distance: float
        The distance between the two points.
    """

    distance = 0
    for i in range(3):
        dim_dist = coord1[i] - coord2[i]

        if box_length:
            dim_dist = dim_dist - box_length * round(dim_dist / box_length)

        dim_dist = dim_dist**2
        distance += dim_dist

    distance = math.sqrt(distance)
    return distance
    
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

    for i in range(num_atoms):
        for j in range(i + 1, num_atoms):

            dist_ij = calculate_distance(
                coordinates[i], coordinates[j], box_length=box_length
            )

            if dist_ij < cutoff:
                interaction_energy = calculate_LJ(dist_ij)
                total_energy += interaction_energy

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
        
    
    return atomic_coordinates, box_length

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

    num_atoms = len(coordinates)

    for j_particle in range(num_atoms):
        if i_particle != j_particle:

            J_position = coordinates[j_particle]
            r_ij = calculate_distance(i_position, J_position, box_length)

            if r_ij < cutoff:
                e_pair = calculate_LJ(r_ij)
                e_total += e_pair

    return e_total

# create a function called run_simulation that takes in simulation parameters and runs the simulation.
def run_simulation(coordinates, box_length, cutoff, reduced_temperature, num_steps, max_displacement=0.1, freq=1000):
    """
    Calculate the interaction energy of a particle with its environment (all other particles in the system).

    Parameters
    ----------
    coordinates: List
        A list of coordinates for all particles in the system
    box_length: float
        Length of the sides of the box created for the simulation
    cutoff : float
        The cut-off distance
    reduced_temperature : float
        Temperature of the system
    num_steps : integer
        Number of times for particle moves
    max_displacement : float
        The maximum displacement for particles
    freq : integer
        The frequency for printing steps and energies from the simulation

    Returns
    -------
    steps : list
        A list of the steps based on the frequency
    energies : list
        A list of the total energies based on the frequency
    """

    # Calculated quantities
    beta = 1 / reduced_temperature

    # # Get initial coordinates (initial system configuration)
    # coordinates, box_length = read_xyz("../data/sample_config1.txt")
    num_particles = len(coordinates)

    delta_energy = 0

    total_energy = calculate_total_energy(coordinates, box_length, cutoff)
    total_energy += calculate_tail_correction(num_particles, box_length, cutoff)

    steps = []
    energies = []
    for step in range(num_steps):

        # 1. Randomly pick one of N particles
        random_particle = random.randrange(num_particles)

        # 2. Calculate the interaction energy of the selected particle with the system and store this value.
        current_energy = calculate_pair_energy(coordinates, random_particle, box_length, cutoff)

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