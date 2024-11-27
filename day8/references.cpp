#include <iostream>

int main(void)
{
    std::string my_string = "Hello, world!";
    std::string & ref_string = my_string;

    ref_string.append(" appended");
    std::cout << "my_string: " << my_string << std::endl;
    std::cout << "ref_string: " << ref_string << std::endl;

    std::cout << "my_string: " << &my_string << std::endl;
    std::cout << "ref_string: " << &ref_string << std::endl;

    double pi = 3.1415;
    const double & ref_pi = pi;
    pi = 3.192837;

    std::cout << "new ref_pi: " << ref_pi << std::endl;

    return 0;
}