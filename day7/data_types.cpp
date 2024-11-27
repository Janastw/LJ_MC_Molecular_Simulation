#include <iostream>
#include <limits> // std::numeric_limits

int main(void)
{
    double a = 30;

    std::cout << "double: " << sizeof(a) << std::endl;
    std::cout << "   int: " << sizeof(int) << std::endl;
    std::cout << "  bool: " << sizeof(bool) << std::endl;
    std::cout << "  long: " << sizeof(long) << std::endl;
    std::cout << "  char: " << sizeof(char) << std::endl;

    std::cout << "limits of int: " << std::numeric_limits<int>::min() << " , " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "limits of long: " << std::numeric_limits<long>::min() << " , " << std::numeric_limits<long>::max() << std::endl;

    std::cout << "limits of unsigned int: " << std::numeric_limits<unsigned int>::min() << " , " << std::numeric_limits<unsigned int>::max() << std::endl;

    unsigned int ui = 0;
    ui = ui - 1;
    std::cout << "negative unsigned int: " << ui << std::endl;

    std::cout << "limits of float: " << std::numeric_limits<float>::min() << " , " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "limits of double: " << std::numeric_limits<double>::min() << " , " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "limits of long double: " << std::numeric_limits<long double>::min() << " , " << std::numeric_limits<long double>::max() << std::endl;

    double x;
    std::cout << "x: " << x << std::endl;
    return 0;
}