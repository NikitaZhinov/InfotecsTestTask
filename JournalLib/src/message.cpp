#include "journal/message.hpp"

#include <iomanip>

journal::Message::Message(const std::string& text, Level level) :
    text_(text),
    level_(level),
    time_(std::time(nullptr)) {}

journal::Message::Message(std::string&& text, Level level) :
    text_(std::move(text)),
    level_(level),
    time_(std::time(nullptr)) {}

void journal::Message::setText(const std::string& new_text) {
    text_ = new_text;
}

void journal::Message::setText(std::string&& new_text) noexcept {
    text_ = std::move(new_text);
}

void journal::Message::setLevel(Level new_level) {
    level_ = new_level;
}

std::string journal::Message::getText() const {
    return text_;
}

journal::Level journal::Message::getLevel() const {
    return level_;
}

time_t journal::Message::getTime() const {
    return time_;
}

std::ostream& journal::operator<<(std::ostream& os, const Message& message) {
    auto t = message.getTime();
    return os << message.getLevel() << " (" << std::put_time(std::localtime(&t), "%c")
              << ") - " << message.getText();
}
