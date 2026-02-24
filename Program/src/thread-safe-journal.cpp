#include "thread-safe-journal.hpp"

ThreadSafeJournal::ThreadSafeJournal(const std::string& file_name,
                                   journal::Level base_level) :
    journal_(file_name, base_level) {}

ThreadSafeJournal::~ThreadSafeJournal() {
    close();
}

void ThreadSafeJournal::push(const journal::Message& new_message) {
    std::lock_guard<std::mutex> lock(mutex_);
    queue_.push(new_message);
    cv_.notify_one();
}

bool ThreadSafeJournal::isActive() {
    std::lock_guard<std::mutex> lock(mutex_);
    return !is_finished_;
}

void ThreadSafeJournal::print() {
    std::unique_lock<std::mutex> lock(mutex_);

    cv_.wait(lock, [&]() { return !queue_.empty() || is_finished_; });

    if (is_finished_) {
        return;
    }

    journal_.addMessage(queue_.front());
    queue_.pop();
}

void ThreadSafeJournal::close() {
    std::lock_guard<std::mutex> lock(mutex_);

    if (is_finished_) {
        return;
    }

    is_finished_ = true;
    journal_.close();
    cv_.notify_all();
}
