# Discussion Questions - Think Python
### 1. What does an assignment statement look like in Python? In C++? What are the differences?
In Python, an assignment statement is simply *variable_name = value* e.g. *my_age = 35*. In C++, the type of variable needs to be specified: *int my_age = 35;*. Python variables are dynamically typed; C++ variables are statically typed and require a semicolon at the end of the statement. In C++ you need to use `double`, `bool`, `int`, or `std: string` at the beginning of the statement for those types. Strings must use double quotes.

### 2. The chapter says that Python variable names can not start with a number. Is the same true for C++ variable names?
It is true for C++ that variable names cannot start with numbers. They must start with a letter or underscore.

### 3. What is an expression? Give an example of an expression Python and in C++.
An expression is a combination of values, variables and operators that can be evaluated to a single value.
* Python example: (x + 5) / 2
* C++ example: (x + 5) / 2

### 4. Compare using code a for loop that counts to 10 in Python and C++. Write at least three sentences about how the loops are the same or different.
Python Code:
    
    for i in range(1, 11):
        print(i)
C++ Code:

    #include <iostream>
    int main(void){
    for(int i = 1; i < 11; i++)
    {
        std::cout << i << std::endl;
    }    
    return 0;}
Both of these codes will count from 1 to 10. The Python code is more easily written. For example, it will automatically increment by 1 where the C++ needs the `i++` part to increment. Additionally, the `<< std::endl;` portion needs to be added to the C++ code so that the resulting evaluation in the terminal adds a new line after each iteration. The Python code does not need that.

### 5. Is there an interactive interpreter for C++? Why or why not?
No. C++ is a compiler langauge so does not need an interpreter. C++ compiles code to be directly processed by the computer.

### 6. Complete Exercise 1 from chapter 2 with both Python and C++.
Exercise 1 Results in Python:
* `42 = n` is not allowed
* `x = y = 1` is allowed. Each `x` and `y` ends up being given a value of **1**
* Adding a semicolon does not seem to affect anything
* Adding a period does not seem to affect numbers but causes an error when added after a string
* You cannot multiply by typing `x y`; you should use `x*y`

Exercise 1 Results in C++:
* `42 = n` is not allowed
* `x = y = 1` is not allowed if you try to initialize it `int x = y = 1;`; it is allowed if you first initialize each `int x = 1;`, `int y = 2;` and then `x = y = 1` is allowed
* Adding a semicolon is expected
* Adding a period is not allowed
* You cannot multiply by typing `x y`; you should use `x*y`