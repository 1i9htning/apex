#pragma once
#include <cmath>
#include <iostream>
#include <limits>

namespace apex {

bool Equal(double a, double b, double epsilon = 1e-12) {
    return std::fabs(a - b) <= epsilon;
}

// bool essentiallyEqual(double a, double b, double epsilon = 1e-12) {
//     return std::fabs(a - b) <= epsilon * std::fmax(std::fabs(a), std::fabs(b));
// }

bool Greater(double a, double b, double epsilon = 1e-12) {
    return (a - b) > epsilon * std::fmax(std::fabs(a), std::fabs(b));
}

bool Less(double a, double b, double epsilon = 1e-12) {
    return (b - a) > epsilon * std::fmax(std::fabs(a), std::fabs(b));
}

}  // namespace apex
