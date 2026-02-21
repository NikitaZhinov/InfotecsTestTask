#pragma once

#include <ostream>
#include <string>
#include <ctime>

#include "level.hpp"

namespace journal {
    /**
     * @brief Presentation of the message in the journal.
     */
    class Message final {
        std::string text_;
        Level level_;
        time_t time_;

    public:
        /**
         * @brief Construct a new Message object.
         *
         * @param text - message text
         * @param level - the importance level of the message
         */
        Message(const std::string& text, Level level = UNIMPORTANT);

        /**
         * @brief Construct a new Message object.
         *
         * @param text - message text
         * @param level - the importance level of the message
         */
        Message(std::string&& text, Level level = UNIMPORTANT);

        /**
         * @brief Set a new message text.
         *
         * @param new_text - a new message text
         */
        void setText(const std::string& new_text);

        /**
         * @brief Set a new message text.
         *
         * @param new_text - a new message text
         */
        void setText(std::string&& new_text) noexcept;

        /**
         * @brief Set the message's importance level.
         *
         * @param new_level - a importance level
         */
        void setLevel(Level new_level);

        /**
         * @brief Get the text of the message.
         *
         * @return std::string
         */
        [[nodiscard]] std::string getText() const;

        /**
         * @brief Get the message's importance level
         *
         * @return Level
         */
        [[nodiscard]] Level getLevel() const;

        /**
         * @brief Get the time when a message was created
         *
         * @return time_t
         */
        [[nodiscard]] time_t getTime() const;
    };

    std::ostream& operator<<(std::ostream& os, const Message& message);
}  // namespace journal
