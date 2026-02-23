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

    std::string formatLevel(Level level);

    Level formatLevel(const std::string& level);

    std::ostream& operator<<(std::ostream& os, Level level);
}  // namespace journal
