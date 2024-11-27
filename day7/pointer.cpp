#include <iostream>

int main(void)
{
    int j = 1234;
    std::cout << "Value of j: " << j << std::endl;
    std::cout << "Address of j: " << &j << std::endl;

    int * pj = &j; // pj points to address of j
    std::cout << "Value of pj: " << pj << std::endl;
    std::cout << "Value of *pj: " << *pj << std::endl;

    *pj = 5678;

    std::cout << "Value of *pj changed!" << j << std::endl;
    std::cout << "New value of j: " << j << std::endl;
    std::cout << "New value of *pj: " << *pj << std::endl;
    std::cout << "Value of pj: " << pj << std::endl;

    double * pd; // = nullptr

    std::cout<< "pd: " << pd << std::endl;
    std::cout << "*pd: " << *pd << std::endl;




    return 0;
}