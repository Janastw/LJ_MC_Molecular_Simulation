import math
import random

# Function to estimate pi using the monte carlo simulation
def estimate_pi(n_samples):

    # Define variable to count points that are generated under the curve
    points_under_curve = 0

    # For loop to generate points from 0 to 1
    for i in range(n_samples):
        x = random.random()
        y = random.random()

        # Checks if generated point is under the curve
        if y < (1 / (1 + x**2)):
            points_under_curve += 1
    
    # Calculate the integral
    monte_carlo_calculation = points_under_curve / n_samples

    # Return estimated pi value
    return monte_carlo_calculation * 4


# Define number of points to be generated
n_samples = 1000

# Print monte carlo integration value
print(estimate_pi(n_samples))
# Print actual number of pi
print(math.pi)


# Test case #1 - checks to see if estimatino is close to pi
assert math.isclose(estimate_pi(10000), 3.14, rel_tol = 0.05)

# Test case #2 - if point generated within the curve
random.seed(1)
print(random.random(), random.random())
random.seed(1)
assert estimate_pi(1) == 4

# Test case #3 - if point generated outside of the curve
random.seed(2)
print(random.random(), random.random())
random.seed(2)
assert estimate_pi(1) == 0

