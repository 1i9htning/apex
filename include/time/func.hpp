#pragma once
#include <chrono>

namespace apex {

namespace time {

template <typename T, typename Rep>
inline void SleepImpl(Rep count) {
    std::this_thread::sleep_for(T(count));
}

inline void SleepH(unsigned count) {
    SleepImpl<std::chrono::hours>(count);
}

inline void SleepM(unsigned count) {
    SleepImpl<std::chrono::minutes>(count);
}

inline void SleepS(unsigned count) {
    SleepImpl<std::chrono::seconds>(count);
}

inline void SleepMs(unsigned count) {
    SleepImpl<std::chrono::milliseconds>(count);
}

inline void SleepUs(unsigned count) {
    SleepImpl<std::chrono::microseconds>(count);
}

inline void SleepNs(unsigned count) {
    SleepImpl<std::chrono::nanoseconds>(count);
}

}  // namespace time

}  // namespace apex
