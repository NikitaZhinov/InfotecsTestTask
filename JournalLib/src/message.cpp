#include "journal/message.hpp"

using namespace journal;

Message::Message(const std::string& text, Level level) : text_(text), level_(level) {}

Message::Message(std::string&& text, Level level) :
    text_(std::move(text)),
    level_(level) {}

void Message::setText(const std::string& new_text) {
    text_ = new_text;
}

void Message::setText(std::string&& new_text) noexcept {
    text_ = std::move(new_text);
}

void Message::setLevel(Level new_level) {
    level_ = new_level;
}

std::string Message::getText() const {
    return text_;
}

Level Message::getLevel() const {
    return level_;
}

time_t Message::getTime() const {
    return time_;
}

std::ostream& journal::operator<<(std::ostream& os, const Message& message) {
    auto t = message.getTime();
    return os << message.getLevel() << " (" << std::asctime(std::localtime(&t)) << ") - "
              << message.getText() << '\n';
}
