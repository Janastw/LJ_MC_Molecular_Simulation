#include <iostream>

int main(void)
{
    // // Check n = 42 worked.
    // int n = 42;
    // std::cout << n << std::endl;
    // // Check 42 = s: error: expected unqualified-id before numeric constant
    // int 42 = s;
    // std::cout << s << std::endl;

    // // Check if x = y = 1 is allowed: error: ‘y’ was not declared in this scope
    // int x = y = 1;
    // std::cout << x << std::endl;
    // std::cout << y << std::endl;

    // Check if x = y = 1 is allowed: It is if you initialize each variable first.
    int x = 1;
    int y = 2;
    x = y = 1;
    std::cout << x << std::endl;
    std::cout << y << std::endl;

    // // Check if semicolon is added: IT'S SUPPOSED TO HAVE A SEMICOLON!
    // int n = 42;
    // std::cout << n << std::endl;

    // // Check if period is added: error: expected ‘,’ or ‘;’ before ‘std’
    // int n = 42.
    // std::cout << n << std::endl.

    // //Check if x*y works: it does!
    // double x = 2;
    // double y = 3;
    // double product = x*y;
    // std::cout << product << std::endl;

    // //Check if x y works: error: expected ‘,’ or ‘;’ before ‘y’
    // double x = 2;
    // double y = 3;
    // double product = x y;
    // std::cout << product << std::endl;

    return 0;
}