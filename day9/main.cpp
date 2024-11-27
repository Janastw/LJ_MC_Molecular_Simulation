#include <iostream>
#include <vector>
#include "temperature.hpp"

using namespace std;


int main(void)
{
    const double temperature = 68.1;
    cout << "Address outside: " << &temperature << endl;

    cout << "Temperature is " << temperature << endl;
    
    double new_temperature = convert_F_to_C(temperature);

    cout << "Temperature is " << temperature << endl;
    cout << "New Temperature is " << new_temperature << endl;

    std::vector<double> temperatures;
    temperatures.push_back(0.0);
    temperatures.push_back(-40.0);
    temperatures.push_back(123.0);

    std::vector<double> new_temperatures = convert_F_to_C(temperatures);

    for(size_t i = 0; i < new_temperatures.size(); i++)
    {
        cout << temperatures[i] << "F is " << new_temperatures[i] << "C" << endl;
    }


    convert_F_to_C();


    return 0;
}