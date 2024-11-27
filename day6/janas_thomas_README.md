# README by TJ

## Steps & Questions / Reflection
1. What type should be used for x and the return type?

Because we will be doing heavier math calculations, we chose to use a double for both the x and the return types. This way we can get more precise calculations, whereas an integer works only as a whole number. Additionally, we tested our method with float values and our results had a higher error than our code using doubles.

2. What should the types of a, b, and n points be? What type should the function return?

The function should always return a double because of the multiplication and division we have in the equation. It most likely would not results in a whole number or low decimal number.
As for a, b, and n, these could possibly be integers, however we would be unsure what our user would input. So a float or double value may be the safer option given our low memory usage anyway.

3. Given the bounds of integration a, b and the number of points, what is the width of the rectangles you will be using?

The width of the rectangles will always be (b - a) / npoints

4. At what points will you need to evaluate the integrand?

5. No question

6. About how many points does it take to start converging to the proper result (4 decimal places)?

With rounding to the 4th decimal, it would be around 25 points.

Reflection:
This was interesting to use C++ here. My group and I were unsure how to tackle the Riemann Sums, though using the graph visualization definitely helped. Once we decided to measure out the steps, and then where the mid point would be, it was easy to navigate making the rectangles. It was interesting to watch the group dynamic with one person sharing the screen and the rest of the group providing input. I like how we just take time to start drawing out our solutions and explain them to each other.

Using the script:
In the main function, line 10 has the code "double area = calculate_area(0, 1, 25)". Change 0 and 1 to be your lower and upper bound of the integral, and change 25 to be the number of points. The purpose is to calculate the integration of 1/(1 + x^2) from point a to point b.

## Discussion Questions

1. C++ is useful for managing memory for projects that require a lot of memory usage. This is because C++ can allocate specific variables to be specific types like integers, floats, or doubles which each have their own specific memory type. Because Python has a more user-friendly coding language, it is easier to create complicated programs with Python.


2. Because C++ can have specific assignments, which specifies bytes (memory) used for each variabel, it may be advantageous to use C++ when there are intensive functions, and Python for more complicated functions but not as intensive. For example, in our simulation project, we could use C++ to code for the functions like 'calculate_LJ' or 'calculate_distance' so we could improve performance there. However 'run_simulation' or even the rest of the code could remain in python because the python language would most likely be faster/easier to code.

3. If Riemann Sums can be used to measure the integration, then that would be best to use in the interest of time/memory. However, if we are using equations that involve more than 2 dimensions, it may be difficult (or impossible) to measure those integrations with Riemann Sums.
