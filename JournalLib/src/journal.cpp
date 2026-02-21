#include "journal/journal.hpp"

#include <stdexcept>

using namespace journal;

bool Journal::checkMessageLevel(const Message& message) const {
    if (message.getLevel() < base_level_) {
        return false;
    }
    return true;
}

Journal::Journal(const std::string& file_name, Level base_level) :
    file_name_(file_name),
    base_level_(base_level) {
    open();
}

Journal::Journal(std::string&& file_name, Level base_level) :
    file_name_(std::move(file_name)),
    base_level_(base_level) {
    open();
}

Journal::~Journal() {
    close();
}

void Journal::open() {
    if (is_open_) {
        journal_file_.close();
    }

    is_open_ = true;

    journal_file_.open(file_name_);

    if (!journal_file_.is_open()) {
        throw std::runtime_error("could not open the file");
    }
}

void Journal::open(const std::string& file_name) {
    file_name_ = file_name;
    open();
}

void Journal::open(std::string&& file_name) {
    file_name_ = std::move(file_name);
    open();
}

void Journal::close() {
    journal_file_.close();
    is_open_ = false;
}

bool Journal::isOpen() const {
    return is_open_;
}

void Journal::setBaseLevel(Level new_base_level) {
    base_level_ = new_base_level;
}

[[nodiscard]] std::string Journal::getFileName() const {
    return file_name_;
}

[[nodiscard]] Level Journal::getBaseLevel() const {
    return base_level_;
}

bool Journal::addMessage(const Message& new_message) {
    return addNewMessage(new_message);
}

bool Journal::addMessage(Message&& new_message) {
    return addNewMessage(std::move(new_message));
}
