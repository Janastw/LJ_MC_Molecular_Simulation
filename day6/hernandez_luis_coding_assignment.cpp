#include <iostream>
#include <cmath>

double calculate_y(double x);
double calculate_area(double a, double b, int npoints);

int main(void)
{
    double pi = 2 * asin(1);
    double actual_area = pi / 4;
    double area = calculate_area(0, 1, 25);

    std::cout << "Area of pi / 4 = " << actual_area << std::endl;
    std::cout << "Calculated area = " << area << std::endl;
}

double calculate_y(double x)
{
    /*
    Parameters
    ----------
    x : double
        x
    integration_points : integer
        The amount of steps between integration

    Return
    ------
    total_area : double
        total area calculated using the integration via summation by the midpoint rule (Riemann sum)
    */
    double y = 1 / (1 + x*x);

    return y;
}

double calculate_area(double a, double b, int npoints)
{
    /*
    Parameters
    ----------
    a, b : double
        a is the lower bound of the integral
        b is the upper bound of the integral
    integration_points : integer
        The amount of steps between integration

    Return
    ------
    total_area : double
        total area calculated using the integration via summation by the midpoint rule (Riemann sum)
    */
    double total_area = 0;
    double dx = (b - a) / npoints; // Width rectangles
    double midpoint;

    while (a < b)
    {
        midpoint = a + dx / 2;
        double y = calculate_y(midpoint);
        total_area += dx * y;
        a += dx;
    }

    return total_area;
}

