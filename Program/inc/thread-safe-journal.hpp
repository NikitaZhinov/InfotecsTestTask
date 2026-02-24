#include <mutex>
#include <queue>
#include <condition_variable>
#include <atomic>

#include <journal/journal.hpp>

/**
 * @brief Provides streaming security of the transmitted data in a separate thread.
 */
class ThreadSafeJournal final {
    std::mutex mutex_;

    std::queue<journal::Message> queue_;
    std::condition_variable cv_;
    std::atomic_bool is_finished_ = false;

    journal::Journal journal_;

public:
    /**
     * @brief Construct a new ThreadSafeJournal object
     *
     * @param file_name name of the journal file
     * @param base_level minimum message importance level (messages below this level will
     * not be added to the journal)
     */
    ThreadSafeJournal(const std::string& file_name, journal::Level base_level);

    /**
     * @brief Destroy the ThreadSafeJournal object
     */
    ~ThreadSafeJournal();

    /**
     * @brief Add new message in the queue.
     * 
     * @param new_message a new message
     */
    void push(const journal::Message& new_message);

    /**
     * @brief Check whether the journal is open.
     * 
     * @return true if journal is open
     * @return false if journal is not open
     */
    bool isActive();

    /**
     * @brief Print message in the journal file.
     */
    void print();

    /**
     * @brief Close the journal.
     */
    void close();
};
