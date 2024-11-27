# import group_11_sodium_mc_numpy as mc
import group_11_sodium_mc_psl as mc

# # Set simulation parameters
# reduced_temperature = 0.9
# num_steps = 2500
# cutoff = 3

# # Set simulation parameters
# reduced_temperature = 0.9
# num_steps = 25000
# cutoff = 3

# Set simulation parameters
reduced_temperature = 0.9
num_steps = 50000
cutoff = 3

# Read initial coordinates
coordinates, box_length = mc.read_xyz("../data/sample_config1.txt")


# Run simulation
mc.run_simulation(coordinates, box_length, cutoff, reduced_temperature, num_steps)