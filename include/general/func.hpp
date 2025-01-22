#pragma once
#include <cmath>
#include <iostream>
#include <limits>
#include <type_traits>

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

template <typename T>
int GetBitImpl(T target, unsigned index) {
    constexpr unsigned bit_count = sizeof(T) * 8;
    if (index >= bit_count)
        return -1;

    T mask = static_cast<T>(1) << index;
    return (target & mask) ? 1 : 0;
}

template <typename T, typename std::enable_if<std::is_fundamental<T>::value, int>::type = 0>
int GetBit(T target, unsigned index) {
    return GetBitImpl(target, index);
}

template <typename T, typename std::enable_if<!std::is_fundamental<T>::value, int>::type = 0>
int GetBit(const T &target, unsigned index) {
    return GetBitImpl(target, index);
}

template <typename T>
bool SetBit(T &target, unsigned index, bool value) noexcept {
    constexpr unsigned bit_count = sizeof(T) * 8;
    if (index >= bit_count)
        return false;

    T mask = static_cast<T>(1) << index;
    target = value ? (target | mask) : (target & ~mask);
    return true;
}

}  // namespace apex
