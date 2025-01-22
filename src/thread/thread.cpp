#include "thread/thread.hpp"

apex::thread::Thread::~Thread() noexcept(false) {
    if (thread_.joinable()) {
        throw apex::thread::ThreadStillRunningError(thread_name_);
    }
}