#include "journal/level.hpp"

#include <cctype>
#include <stdexcept>

std::string journal::formatLevel(Level level) {
    switch (level) {
        case UNIMPORTANT:
            return "UNIMPORTANT";

        case IMPORTANT:
            return "IMPORTANT";

        case VERY_IMPORTANT:
            return "VERY_IMPORTANT";

        case BASIC_NECESSITIES:
            return "BASIC_NECESSITIES";

        default:
            break;
    }

    throw std::runtime_error("undefined level");
}

journal::Level journal::formatLevel(std::string level) {
    for (char& c : level) {
        c = std::toupper(c);
    }

    if (level == "UNIMPORTANT") {
        return UNIMPORTANT;
    } else if (level == "IMPORTANT") {
        return IMPORTANT;
    } else if (level == "VERY_IMPORTANT") {
        return VERY_IMPORTANT;
    } else if (level == "BASIC_NECESSITIES") {
        return BASIC_NECESSITIES;
    }

    throw std::runtime_error("undefined level string");
}

std::ostream& journal::operator<<(std::ostream& os, Level level) {
    return os << formatLevel(level);
}
