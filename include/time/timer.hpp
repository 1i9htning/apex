#pragma once
#include <chrono>

namespace apex {

namespace time {

class Timer {
public:
    Timer() {
        Reset();
    }

    ~Timer() = default;

    inline void Reset() {
        start_time = std::chrono::high_resolution_clock::now();
    }

    template <typename T>
    inline typename T::rep GetDuration() {
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<T>(end_time - start_time);
        return duration.count();
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
};

}  // namespace time
}  // namespace apex
