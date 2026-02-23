#include "journal/journal.hpp"

#include <stdexcept>

bool journal::Journal::checkMessageLevel(const Message& message) const {
    if (message.getLevel() < base_level_) {
        return false;
    }
    return true;
}

journal::Journal::Journal(const std::string& file_name, Level base_level) :
    file_name_(file_name),
    base_level_(base_level) {
    open();
}

journal::Journal::Journal(std::string&& file_name, Level base_level) :
    file_name_(std::move(file_name)),
    base_level_(base_level) {
    open();
}

journal::Journal::~Journal() {
    close();
}

void journal::Journal::open() {
    if (is_open_) {
        journal_file_.close();
    }

    is_open_ = true;

    journal_file_.open(file_name_);

    if (!journal_file_.is_open()) {
        throw std::runtime_error("could not open the file");
    }
}

void journal::Journal::open(const std::string& file_name) {
    file_name_ = file_name;
    open();
}

void journal::Journal::open(std::string&& file_name) {
    file_name_ = std::move(file_name);
    open();
}

void journal::Journal::close() {
    journal_file_.close();
    is_open_ = false;
}

bool journal::Journal::isOpen() const {
    return is_open_;
}

void journal::Journal::setBaseLevel(Level new_base_level) {
    base_level_ = new_base_level;
}

[[nodiscard]] std::string journal::Journal::getFileName() const {
    return file_name_;
}

[[nodiscard]] journal::Level journal::Journal::getBaseLevel() const {
    return base_level_;
}

bool journal::Journal::addMessage(const Message& new_message) {
    return addNewMessage(new_message);
}

bool journal::Journal::addMessage(Message&& new_message) {
    return addNewMessage(std::move(new_message));
}
