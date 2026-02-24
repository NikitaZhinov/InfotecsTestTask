#include "commands.hpp"

#include <cstdlib>
#include <iostream>

Command::Command(const std::string& name, const func_signature& func) :
    name_(name),
    func_(func) {}

void Command::operator()(ApplicationCommands& app) {
    func_(app);
}

std::string Command::getName() const {
    return name_;
}

void ApplicationCommands::addCommand(const Command& cmd) {
    commands_.emplace_back(cmd);
}

void ApplicationCommands::start() {
    is_run_ = true;

    while (is_run_) {
        std::cout << "Chose the command:\n";

        for (size_t i = 0, max_i = commands_.size(); i < max_i; ++i) {
            std::cout << '[' << i << "] " << commands_[i].getName() << '\n';
        }

        int i = -1;
        std::cin >> i;

#ifdef _WIN32
        std::system("cls");
#else
        std::system("clear");
#endif

        if (i < 0 || i >= static_cast<int>(commands_.size())) {
            std::cout << "Undefined command!\n";
        } else {
            commands_[i](*this);
        }

        std::cout << '\n';
    }
}

void ApplicationCommands::stop() {
    is_run_ = false;
}
