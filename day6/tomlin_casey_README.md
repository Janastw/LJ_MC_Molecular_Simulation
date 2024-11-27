# Day 6 Group Assignment - Integration via Summation 
This code calculates the Riemann Sum of a function using the midpoint rule.

### Using the Script
After downlaoding the file, the user can choose which bounds they want to calculate by inputting them in place of **a** and **b** and the number of integration points with **npoints**. The greater the value of **npoints** the closer to *pi/4* the value will be.

## Reflection

### Steps and Questions

1. *Q: What type should be used for x and the return type?*
The `double` type will be used for **x** since it will need to represent values with decimal points. The return type will also be `double` becuase the output of the function should be a non-integer value.

2. *Q: What should the types of a,b and npoints be? What type should the function return?*
`a` and `b` should be `double` types in the code to account for whatever the user may want to input though most likely an integer will be used. `npoints` should be an integer because this is basically the number of steps that will put into the function creating our number of boxes for integration. It would be illogical to try to use a portion of a Riemann Sum rectangle to estimate the value of the integral. The function will return `total_area` with a type of `double`.

3. *Q: Given the bounds of integration a,b and the number of points, what is the width of the rectangles you will be using?*
We calculate the box width with **dx = b-a/npoints**. This will choose the appropriate box width of the Riemann Sum given the upper bound, lower bound and number of integration points.

4. *Q: At what points will you need to evaluate the integrand?*
The integrand will be evaluated for each change in **x** to calculate the height of the box.

6. *Q: About how many points does it take to start converging to the proper result (4 decimal places)?*
At around 25 **npoints**, with rounding the result of our code gets to the 4 decimal places desired. Where the actual area is 0.789398 and the calculated areas is 0.789431.



### Discussion Questions

1. Since **C++** is fast and efficient as a compiled language, it is better suited to performance-based projects that are large-scale and need a lot of fine-tuning of the code. **Python**, on the other hand, is a bit easier to understand and read allowing for faster code development at the cost of resource-intensity and lack of fine tuning.

2. We would use **C++** to perform calculations that required more time and memory, whereas **Python** would be integrated where the user would be interacting with the code. In the case of our Monte Carlo Simulation code, the `calculate_distance` and `calculate_LJ` functions would be run with **C++** since they use a lot of CPU power and the `run_simulation` function could be handled by the user in **Python**.

3. The Monte Carlo simulation better handles random events or seemingly random events. The only reason why the Riemann Sum was so effective is because we were working with so few dimensions. It becomes a lot harder to calculate a Riemann Sum when the equation becomes too much more complex. 


