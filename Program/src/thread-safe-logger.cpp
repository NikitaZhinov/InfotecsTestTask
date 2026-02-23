#include "thread-safe-logger.hpp"

ThreadSafeLogger::ThreadSafeLogger(const std::string& file_name,
                                   journal::Level base_level) :
    journal_(file_name, base_level) {}

ThreadSafeLogger::~ThreadSafeLogger() {
    close();
}

void ThreadSafeLogger::push(const journal::Message& new_message) {
    std::lock_guard<std::mutex> lock(mutex_);
    queue_.push(new_message);
    cv_.notify_one();
}

bool ThreadSafeLogger::isActive() const {
    return !is_finished_;
}

void ThreadSafeLogger::print() {
    std::unique_lock<std::mutex> lock(mutex_);

    cv_.wait(lock, [&]() { return !queue_.empty() || is_finished_; });

    if (is_finished_) {
        return;
    }

    journal_.addMessage(queue_.front());
    queue_.pop();
}

void ThreadSafeLogger::close() {
    std::lock_guard<std::mutex> lock(mutex_);

    if (is_finished_) {
        return;
    }

    // while (!queue_.empty()) {
    //     journal_.addMessage(queue_.front());
    //     queue_.pop();
    // }

    is_finished_ = true;
    cv_.notify_all();
}
