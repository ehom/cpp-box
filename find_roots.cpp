#include <iostream>
#include <cmath>

std::pair<double, double> findRoots(double a, double b, double c)
{
    std::pair<double, double> result;

    // pre-compute parts of the equation
    double sqrt_result = std::sqrt(b*b - 4*a*c);
    double divisor = 2 * a;

    result.first = (-b + sqrt_result) / divisor;
    result.second = (-b - sqrt_result) / divisor;

    return result;
}

int main() 
{
    std::pair<double, double> roots = findRoots(2, 10, 8);
    std::cout << roots.first << std::endl;
    std::cout << roots.second << std::endl;
}
