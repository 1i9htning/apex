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
    inline Thread(const std::string& thread_name, Callable&& func, Args&&... args) : thread_name_(thread_name), exit_flag_(false) {
        thread_ = std::thread(std::forward<Callable>(func), std::forward<Args>(args)...);
        pthread_setname_np(thread_.native_handle(), thread_name.c_str());
    }

    Thread(const Thread&) = delete;
    Thread& operator=(const Thread&) = delete;

    Thread(Thread&& other) : thread_(std::move(other.thread_)),
                             thread_name_(std::move(other.thread_name_)),
                             exit_flag_(other.exit_flag_.load()) {}

    Thread& operator=(Thread&& other) {
        if (this == &other) {
            return *this;
        }

        if (thread_.joinable()) {
            throw apex::thread::ThreadStillRunningError(thread_name_);
        }

        thread_ = std::move(other.thread_);
        thread_name_ = std::move(other.thread_name_);
        exit_flag_.store(other.exit_flag_.load());

        return *this;
    }

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
