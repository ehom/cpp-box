#include <iostream>
#include <cmath>

using Roots = std::pair<double, double>;

auto operator<<(std::ostream& o, const Roots& roots) -> std::ostream&;
auto find_roots(double a, double b, double c) -> Roots;

auto main() -> int {

    Roots roots = find_roots(2, 10, 8);

    std::cout << roots << std::endl;

    return 0;
}

auto operator<<(std::ostream& o, const Roots& roots) -> std::ostream& {

    o << roots.first << ", " << roots.second;

    return o;
}

auto find_roots(double a, double b, double c) -> Roots {

    // Pre-compute parts of the equation
    double sqrt_result = std::sqrt(b * b - 4 * a * c);
    double divisor = 2 * a;

    Roots roots;

    roots.first = (-b + sqrt_result) / divisor;
    roots.second = (-b - sqrt_result) / divisor;

    return roots;
}
