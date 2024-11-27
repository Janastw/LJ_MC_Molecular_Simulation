#pragma once // this is ifndef/define/endif below
#ifndef _TEMPERATURE_HPP
#define _TEMPERATURE_HPP


#include <vector>


/*! \brief Converts a temperature from Celsius Fahrenheit
 *
 *   Given a temperature in clesius, return the value in Fahrenheit
 *   \param [in] temperature The temperature in Celsius
 *   \return The temperature \p temperature converted in Fahrenheit 
*/
double convert_F_to_C(const double & temperature = 0.0);
std::vector<double> convert_F_to_C(const std::vector<double> & temperatures);

#endif