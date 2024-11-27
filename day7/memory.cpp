#include <iostream>

int main(void)
{
    int n_doubles = 16;

    double * data = new double[n_doubles];

    for(int i = 0; i < n_doubles; i++)
    {
        data[i] = 3.1415 * i;
    }
    for(int i = 0; i < n_doubles; i++)
    {
        std::cout << "Element " << i << ": " << data[i] << std::endl;
    }

    std::cout << data[1] << std::endl;

    delete [] data;

    std::cout << data[1] << std::endl;
    
    return 0;
}