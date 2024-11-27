# Discussion by TJ

1. Assignment statement:
    Python
        
        x = 0           # No assignment necessary          
        x = "Hello"
        x = 'h'
    
    C++
        
        int x = 0;      // int, double, float must be specified
        double x = 0;
        std::string x = "Hello"; // std string must be specified
        char x = 'h';

2. Can C++ variables start with a number?
    No, the variable names can not start with a number.

3. What is an expression?
    An expression is a combination of values, operators and variables.

    Python Example:

        800
    
    C++ Example:

        800

4. For loops in Python and C++
    Python:

        for i in range(10):
            ...
        
    C++:
        
        for (int i = 0; i < 10; i++)
        {
            ...
        }
    Both C++ and Python for loops can still achieve the same goals. In C++, you have to have 3 sections specifed in your for loop, sets the variable, makes the comparison using the varibale, and then what happens to that variable at the end of the for loop. In Python, it is assumed that i will have 1 added to it each time it loops, so it does not need to be specified. Additionally, C++ requires "{ }" to hold the code for your for loop, whereas Python requires specific indentation (no brackets needed) after a for loop is made.

5. Is there an interactive interpreter for C++?
        
    No, because the source code is compiled into machine language and then executed directly. It does not need/use an interpreter.

6. For Python, the ";" at the end of the statement works! However, for both Python and C++, assigning 42 = n does not work and neither does leaving a "." at the end of a statement, nor multiplying variables by just writing -> x y. Although, of course in Python, if you intialize a variable like x = 1, then leaving a "." will act as a decimal.
    