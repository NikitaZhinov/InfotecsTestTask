#pragma once

#include <ostream>

namespace journal {
    /**
     * @brief Listing the levels of importance of the message in the journal.
     */
    enum Level {
        UNIMPORTANT = 0,
        IMPORTANT,
        VERY_IMPORTANT,
        BASIC_NECESSITIES
    };

    /**
     * @brief Converts an enumeration to a string.
     *
     * @param level an enumeration
     * @throw std::runtime_error if the value of the enumeration is indefinite
     * @return std::string
     */
    std::string formatLevel(Level level);

    /**
     * @brief Converts a string to an enumeration.
     *
     * @param level a string
     * @throw std::runtime_error if the string does not match the enumeration value
     * @return Level
     */
    Level formatLevel(std::string level);

    std::ostream& operator<<(std::ostream& os, Level level);
}  // namespace journal
