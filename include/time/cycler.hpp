#pragma once
#include <chrono>
#include <thread>

#include "../general/func.hpp"

namespace apex {

namespace time {

class Cycler {
public:
    Cycler(double target_frequency);

    ~Cycler() = default;

    void Sleep();

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> prev_loop_time_point_;
    double time_interval_;  // Unit is ns
};

}  // namespace time
}  // namespace apex
