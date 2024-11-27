#include <iostream>
#include <cmath>

double calculate_density(double number_of_molecules, double box_length);
double calculate_solute_contribution(double C1, double V1, double C2);

int main(void)
{
    std::cout << calculate_density(2000, 10) << std::endl;

    std::cout << calculate_solute_contribution(100, 100, 50) << std::endl;

// Not supposed to be this?
// V2_contribution = V2 - V1

    return 0;
}

double calculate_density(double number_of_molecules, double box_length)
{
    
    double volume = box_length * box_length * box_length;
    double density = number_of_molecules / volume;
    return density;
}

double calculate_solute_contribution(double C1, double V1, double C2)
{
    double V2 = C1 * V1 / C2;
    return V2;
}