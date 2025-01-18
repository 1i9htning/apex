#pragma once
#include <exception>
#include <string>

namespace apex {

namespace thread {

class ThreadStillRunningError : public std::exception {
public:
    ThreadStillRunningError() = default;
    ThreadStillRunningError(const std::string& error)
        : err_("apex::thread::Thread [" + error + "] is still running. Must call Join() or Detach() before destruction.") {}

    const char* what() const noexcept override {
        return err_.c_str();
    }

private:
    std::string err_;
};

}  // namespace thread
}  // namespace apex