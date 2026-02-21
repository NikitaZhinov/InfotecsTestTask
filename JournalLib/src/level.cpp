#include "journal/level.hpp"

using namespace journal;

std::ostream& journal::operator<<(std::ostream& os, Level level) {
    switch (level) {
        case UNIMPORTANT:
            return os << "UNIMPORTANT";

        case IMPORTANT:
            return os << "IMPORTANT";

        case VERY_IMPORTANT:
            return os << "VERY_IMPORTANT";

        case BASIC_NECESSITIES:
            return os << "BASIC_NECESSITIES";
    }

    return os;
}
