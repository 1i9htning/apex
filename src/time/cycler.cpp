#include "time/cycler.hpp"

apex::time::Cycler::Cycler(double target_frequency)
    : time_interval_(0),
      prev_loop_time_point_(std::chrono::high_resolution_clock::now()) {
    time_interval_ = apex::Equal(target_frequency, 0.0) ? 0.0 : (1000000000 / target_frequency);
}

void apex::time::Cycler::Sleep() {
    auto now = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::nanoseconds>(now - prev_loop_time_point_).count();
    int64_t sleep_time = time_interval_ - elapsed_time;
    if (sleep_time > 0) {
        std::this_thread::sleep_for(std::chrono::nanoseconds(sleep_time));
    }
    prev_loop_time_point_ = std::chrono::high_resolution_clock::now();
}