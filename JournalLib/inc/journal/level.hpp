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

    std::ostream& operator<<(std::ostream& os, Level level);
}  // namespace journal
