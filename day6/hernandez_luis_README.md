# Riemann Sum Integration of $f(x) = 1/(1+x^2)$
## Description
This is a C++ code to calculate the value of $\pi$/4 using the Riemann Sum integration of $f(x) = 1/(1+x^2)$ from (0,1).

## Using the Script
* Download and open the file *hernandez_luis_coding_assignment.cpp*
* In the `main` function of the file, adjust the third parameter in the `calculate_area` statement to choose the `npoints` to be calculated as the midpoints of the Riemann sum rectangles
* save the file
* In a terminal execute the commmand: 
    * *g++ hernandez_luis_coding_assignment.cpp -o hernandez_luis_coding_assignment*
* Execute the command: 
    * *./hernandez_luis_coding_assignment*
* Successful run should provide `actual_area` and `calculated_area`

## Reflection

### Steps and Questions

#### What type should be used for x and the return type?
Double and float types were tested on x and the return. Double, having higher precision, provided a better estimation for the final result of $\pi$/4

#### What should the types of a,b and npoints be? What type should the function return?
* `a` should be `double`
* `b` should be `double`
* `npoints` should be `int`
* The return should be `double`

#### Given the bounds of integration a,b and the number of points, what is the width of the rectangles you will be using
The width of the rectangles `dx` = (`b` - `a`) / `npoints`

#### At what points will you need to evaluate the integrand?
The first point to be integrated will be at x = a + dx/2. From there, we will add dx to a for each step until x < b is no longer true

#### About how many points does it take to start converging to the proper result (4 decimal places)?
Using **25** points, we get within **0.0001**.


### Discussion Questions
#### What kinds of projects are best suited for C++? What about Python?
C++ should be used for complex projects that require high performance and use a lot of memory. Python should be used for projects that need to be developed quickly and easily.

#### Can you think of a use case for mixing both languages (that is, a single project that somehow uses both C++ and Python)? What would each language do in such a project?
We could use a mix of both languages for the Monte Carlo simulation of particle interactions. C++ could be used for the computationally expensive functions that are repeatedly called. Python can be kept for code that is intended to interact with the user and might need to be rapidly edited.

#### We have now seen the Monte-Carlo method and the Riemann Sum method for approximating integrals. You will notice that the number of integration points for the Riemann Sum method is much less than the Monte-Carlo method. Why would you ever use the Monte-Carlo method?
The Monte-Carlo method should be used for more complex proglems. The Riemann Sum method should be used for integrating in one dimension. The Monte-Carlo method will likely perform better for higher dimension integrations.