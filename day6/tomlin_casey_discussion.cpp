// Exercise 1 from Think Python
#include <iostream>

int main(void)
{
int n = 42;
// int 42 = n, variables cannot start with a number

int x = 0;
int y = 0;
x = y = 1; // this is allowed as long as both variables are initialized first

// int n = 30. , each line needs to end with ; so a period does not work

x = 1;
y = 2;
// int x y; , multiplication does not work this way in C++

// int x*y; , multiplication must be assigned to a variable in C++
int z = x * y;
}