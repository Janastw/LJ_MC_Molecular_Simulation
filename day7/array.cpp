#include <iostream>

int main(void)
{
    int arr[10];

    for(int i = 0; i < 10; i++)
    {
        // set the i-th value to 2*i
        arr[i] = 2*i;
    }

    for(int i = 0; i <10; i++)
    {
        std::cout << "Element " << i << ": " << arr[i] << std::endl;
    }
    arr[10] = 9999;
    std::cout << "Element 10: " << arr[10] << std::endl;


    return 0;
}