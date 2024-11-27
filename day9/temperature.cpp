#include <iostream>
#include <vector>

using namespace std;



double convert_F_to_C(const double & temperature)
{
     cout << "Address inside: " << &temperature << endl;
    return (temperature - 32.0) * (5.0 / 9.0);
}

std::vector<double> convert_F_to_C(const std::vector<double> & temperatures)
{

    int vector_size = temperatures.size();
    
    std::vector<double> converted;

    for (size_t i = 0; i < vector_size; i++)
    {
        converted.push_back((temperatures[i] - 32.0) * (5.0 / 9.0));
    }

    return converted;
}