#pragma once
#include <atomic>
#include <string>
#include <thread>

#include "./exception.hpp"

namespace apex {

namespace thread {

class Thread {
public:
    template <typename Callable, typename... Args>
    inline Thread(const std::string &thread_name, Callable &&func, Args &&...args) : thread_name_(thread_name), exit_flag_(false) {
        thread_ = std::thread(std::forward<Callable>(func), std::forward<Args>(args)...);
        pthread_setname_np(thread_.native_handle(), thread_name.c_str());
    }

    template <typename Callable, typename... Args>
    inline Thread(const std::string &thread_name, int frequency, Callable &&func, Args &&...args) : thread_name_(thread_name), exit_flag_(false) {
        if (frequency != 0) {
            thread_ = std::thread([frequency, func = std::forward<Callable>(func), ... args = std::forward<Args>(args)]() mutable {
                while (!exit_flag_) {
                    func(args...);
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000 / frequency));
                }
            });
        } else {
            thread_ = std::thread(std::forward<Callable>(func), std::forward<Args>(args)...);
        }

        pthread_setname_np(thread_.native_handle(), thread_name.c_str());
    }

    Thread(const Thread &) = delete;
    Thread &operator=(const Thread &) = delete;

    Thread(Thread &&other) = delete;
    Thread &operator=(Thread &&other) = delete;

    ~Thread() noexcept(false);

    inline void Stop() {
        exit_flag_ = true;
        Join();
    }

    inline void Join() {
        if (thread_.joinable()) {
            thread_.join();
        }
    }

    inline void Detach() {
        if (thread_.joinable()) {
            thread_.detach();
        }
    }

private:
    std::thread thread_;
    std::string thread_name_;

    std::atomic<bool> exit_flag_;
};

}  // namespace thread
}  // namespace apex
