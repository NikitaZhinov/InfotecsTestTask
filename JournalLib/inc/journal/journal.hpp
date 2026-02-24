#pragma once

#include <string>
#include <fstream>

#include "message.hpp"

namespace journal {
    /**
     * @brief Stores messages indicating the degree of importance. Messages with a
     * lower-than-basic importancelevel will not be added.
     */
    class Journal final {
        std::string file_name_;
        Level base_level_;

        std::ofstream journal_file_;
        bool is_open_ = true;

        bool checkMessageLevel(const Message& message) const;

        template <class MessageT> inline bool addNewMessage(MessageT&& new_message) {
            bool is_can_add = checkMessageLevel(new_message);
            if (is_can_add) {
                journal_file_ << std::forward<MessageT>(new_message) << '\n'
                              << std::flush;
            }
            return is_can_add;
        }

    public:
        /**
         * @brief Construct a new Journal object.
         *
         * @param file_name name of the journal file
         * @param base_level minimum message importance level (messages below this level
         * will not be added to the journal)
         */
        Journal(const std::string& file_name, Level base_level = UNIMPORTANT);

        /**
         * @brief Construct a new Journal object.
         *
         * @param file_name name of the journal file
         * @param base_level minimum message importance level (messages below this level
         * will not be added to the journal)
         */
        Journal(std::string&& file_name, Level base_level = UNIMPORTANT);

        /**
         * @brief Destroy the Journal object.
         */
        ~Journal();

        /**
         * @brief Open the last specified journal file.
         * 
         * @throw std::runtime_error if clould not open the file
         */
        void open();

        /**
         * @brief Open the journal file.
         *
         * @throw std::runtime_error if clould not open the file
         * @param file_name a journal file name.
         */
        void open(const std::string& file_name);

        /**
         * @brief Open the journal file.
         *
         * @throw std::runtime_error if clould not open the file
         * @param file_name a journal file name.
         */
        void open(std::string&& file_name);

        /**
         * @brief Close the journal file.
         */
        void close();

        /**
         * @brief Сheck if the journal is open.
         *
         * @return true if journal is open
         * @return false if journal is not open
         */
        bool isOpen() const;

        /**
         * @brief Set a minimum level of message importance. Messages below this level
         * will not be added to the journal.
         *
         * @param new_base_level minimum message importance level
         */
        void setBaseLevel(Level new_base_level);

        /**
         * @brief Get the file name of journal.
         *
         * @return std::string
         */
        [[nodiscard]] std::string getFileName() const;

        /**
         * @brief Get the minimum message importance level
         *
         * @return Level
         */
        [[nodiscard]] Level getBaseLevel() const;

        /**
         * @brief Add a new message.
         *
         * @param new_message a new message
         * @return true if the message has been added
         * @return false if the message has been added
         */
        bool addMessage(const Message& new_message);

        /**
         * @brief Add a new message.
         *
         * @param new_message a new message
         * @return true if the message has been added
         * @return false if the message has been added
         */
        bool addMessage(Message&& new_message);
    };
}  // namespace journal
