#pragma once
#include <string>
#include <thread>

#include "./exception.hpp"

namespace apex {

namespace thread {

class Thread {
public:
    template <typename Callable, typename... Args>
    inline Thread(const std::string &thread_name, Callable &&func, Args &&...args) : thread_name_(thread_name) {
        thread_ = std::thread(std::forward<Callable>(func), std::forward<Args>(args)...);
        pthread_setname_np(thread_.native_handle(), thread_name.c_str());
    }

    Thread(const Thread &) = delete;
    Thread &operator=(const Thread &) = delete;

    Thread(Thread &&other) = delete;
    Thread &operator=(Thread &&other) = delete;

    ~Thread() noexcept(false);

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
};

}  // namespace thread
}  // namespace apex
