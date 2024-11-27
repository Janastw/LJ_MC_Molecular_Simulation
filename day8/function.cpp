#include <iostream>
#include <vector>

using namespace std;

namespace msse_temperature{}

double convert_F_to_C(const double & temperature = 0.0)
{
     cout << "Address inside: " << &temperature << endl;
    return (temperature - 32.0) * (5.0 / 9.0);
}

vector<double> convert_F_to_C(const vector<double> & temperatures)
{

    int vector_size = temperatures.size();
    
    vector<double> converted;

    for (size_t i = 0; i < vector_size; i++)
    {
        converted.push_back((temperatures[i] - 32.0) * (5.0 / 9.0));
    }

    return converted;
}


int main(void)
{
    const double temperature = 68.1;
    cout << "Address outside: " << &temperature << endl;

    cout << "Temperature is " << temperature << endl;
    
    double new_temperature = convert_F_to_C(temperature);

    cout << "Temperature is " << temperature << endl;
    cout << "New Temperature is " << new_temperature << endl;

    vector<double> temperatures;
    temperatures.push_back(0.0);
    temperatures.push_back(-40.0);
    temperatures.push_back(123.0);

    vector<double> new_temperatures = convert_F_to_C(temperatures);

    for(size_t i = 0; i < new_temperatures.size(); i++)
    {
        cout << temperatures[i] << "F is " << new_temperatures[i] << "C" << endl;
    }


    convert_F_to_C();


    return 0;
}