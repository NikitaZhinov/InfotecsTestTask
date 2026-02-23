#include <mutex>
#include <queue>
#include <condition_variable>
#include <atomic>

#include <journal/journal.hpp>

class ThreadSafeLogger final {
    std::mutex mutex_;

    std::queue<journal::Message> queue_;
    std::condition_variable cv_;
    std::atomic_bool is_finished_ = false;

    journal::Journal journal_;

public:
    ThreadSafeLogger(const std::string& file_name, journal::Level base_level);

    ~ThreadSafeLogger();

    void push(const journal::Message& new_message);

    bool isActive() const;

    void print();

    void close();
};
