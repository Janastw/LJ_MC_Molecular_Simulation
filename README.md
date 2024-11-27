# Evaluation of Monte Carlo Code Performance
## Description
Three Monte Carlo scripts were created to run particle simulations:
* Python Standard Library Version: *group_11_sodium_mc_psl.py*
* Python NumPy Version: *group_11_sodium_mc_numpy.py*
* C++ Version: *group_11_sodium_mcsim.cpp*

For each version, 9 simulations were completed: 3 conditions each with 3 trials. The `coordinates` and `box_length` were taken from the NIST sample_config1.txt file. All trials used `cutoff` = **3** and `reduced_temperature` = **0.9**. The `num_steps` parameter was set to either **2500**, **25000** or **50000** to provide the three different conditions. The terminal command `time` was used to capture the `real` time it took to run each of the 27 simulations. After an initial analysis, simulations were completed again; this time, an additional 9 simulations were completed for C++ using `-O3` optimization flat during the compiling step. The C++ had also been rewritten to pass constant references in some of the functions.

## Using the Scripts
### Running the Python scripts
* Open *group_11_sodium_run_sim.py*.
    * To run the numpy version, uncomment line 1 *import group_11_sodium_mc_numpy as mc* and comment line 2 *import group_11_sodium_mc_psl as mc*.
    * To run the standard python version, comment line 1 *import group_11_sodium_mc_numpy as mc* and uncomment line 2 *import group_11_sodium_mc_psl as mc*.
    * Set your simulation parameters and save the file.
* In a terminal, execute the command *time python hernandez_luis_run_sim.py*.
* A successful run should print out `steps` and `energies` along with a `time` report.

### Running the C++ script
* Open *group_11_sodium_mcsim.cpp*.
    * In the `main` function, set your parameters for the `run_simulation` function.
* In a terminal, execute the command *g++ group_11_sodium_mcsim.cpp -o group_11_sodium_mcsim*.
    * Alternatively, compile with an optimization flag and execute *g++ -O3 group_11_sodium_mcsim.cpp -o group_11_sodium_mcsim*
* Then, execute the command *time ./group_11_sodium_mcsim*.
* A successful run should print out `steps` and `energies` along with a `time` report.

## Analysis and Discussion
### Question 1: Which is the fastest version?
* For the first set of simulations (Figure 1), C++ was faster than PSL, but not as fast as numpy. C++ was the fastest during the tests with the lowest number of steps, however it did not scale as well with the larger operations as the Numpy code. For the second set of simulations (Figure 2), the C++ version compiled with optimization flag `-O3` was the fastest. Although C++ was considerably fast, precision of the results wasn't as apparent due to some backend truncation of digits. There is a way to recover this data and show it in the results, but that is beyond the scope of this class.
* Figure 1: Box Chart Comparison of Performance of PSL, NumPy and C++ Versions of the code
    * ![alt text](comparison_box_chart.png)
* FIgure 2: Box Chart Comparison of Performance of PSL, NumPy and C++ Versions of the code with optimization flag -O3 alternative
    * ![alt text](comparison_box_chart_with_O3.png)

### Question 2: Do the different versions scale in distinct ways?
* The Python Standard Library and C++ versions have a directly proportional relationship between the number of steps that the simulations run and the time to complete. The performance of the NumPy version does not scale linearly with the number of steps. It sems to get relatively better as the steps increase.

### Question 3: Can you identify potential reasons for observed performance variations?
* Looking at the raw time numbers of User, Sys and Real in Figure 2, it appears that the NumPy code pushes a lot of the processing time out of the code itself and onto the CPU to perform, hence the higher run times of Sys in comparison to those of the C++ and PSL codes.NumPy handles large arrays of data by operating on the entire set at once as opposed to PSL operations that need to be performed step-wise via `for` loops. The C++ is executed much faster than the rest when compiled with the `-O3` optimization flag. This process increases the time it takes to compile, but we observe a valuable increase in performance at run-time.
* Figure 3: Performance Results for Set 1
    * ![alt text](time_results_table.png)
* Figure 4: Performance Results for Set 1
    * ![alt text](time_results_table_2.png)

### Question 4: Is there a particular version you preferred to write?
* Our group agrees that NumPy is better to write this type of code with. The difficulties of writing code with NumPy is due to the initial learning curve being rather steep. One has to think about and visualize array operations and the potential pitfalls of those operations. But in the end, once the user understands, it is much easier to perform operations on large datasets.  

### Authors
Casey Tomlin

Luis Hernandez

Thomas Janas