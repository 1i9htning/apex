#pragma once
#include <chrono>
#include <thread>

namespace apex {

namespace time {

namespace sleep {

inline void Hours(unsigned short count) {
    std::this_thread::sleep_for(std::chrono::hours(count));
}

inline void Minutes(unsigned short count) {
    std::this_thread::sleep_for(std::chrono::minutes(count));
}

inline void Seconds(unsigned count) {
    std::this_thread::sleep_for(std::chrono::seconds(count));
}

inline void Milliseconds(unsigned count) {
    std::this_thread::sleep_for(std::chrono::milliseconds(count));
}

inline void Microseconds(unsigned count) {
    std::this_thread::sleep_for(std::chrono::microseconds(count));
}

inline void Nanoseconds(unsigned count) {
    std::this_thread::sleep_for(std::chrono::nanoseconds(count));
}

};  // namespace sleep

}  // namespace time

}  // namespace apex
