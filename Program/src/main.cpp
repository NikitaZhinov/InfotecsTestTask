#include <iostream>
#include <istream>
#include <thread>

#include <journal/journal.hpp>

#include "commands.hpp"
#include "thread-safe-journal.hpp"

static std::string getFileName(int argc, const char* argv[]) {
    std::string file_name;

    switch (argc) {
        case 1:
            std::cout << "Enter a journal name: ";
            std::cin >> file_name;
            break;

        default:
            file_name = argv[1];
            break;
    }

    return file_name;
}

static journal::Level getBaseLevel(int argc, const char* argv[]) {
    journal::Level level = journal::UNIMPORTANT;

    switch (argc) {
        case 1:
        case 2:
            break;

        default:
            level = journal::formatLevel(argv[2]);
            break;
    }

    return level;
}

static void writeMessage(ThreadSafeJournal& logger) {
    while (logger.isActive()) {
        logger.print();
    }
}

static journal::Level getMessageLevel() {
    journal::Level level = journal::UNIMPORTANT;

    while (true) {
        std::string level_str;
        std::cout << "Enter the importance level: ";
        std::cin >> level_str;

        try {
            level = journal::formatLevel(level_str);
            break;
        } catch (const std::runtime_error&) {
            std::cout << "Undefined level!\n";
        }
    }

    return level;
}

static std::string getMessageText() {
    std::cout << "Enter the text: ";

    std::string text;
    std::getline(std::cin >> std::ws, text);

    return text;
}

static void getMessage(ThreadSafeJournal& logger) {
    auto level = getMessageLevel();
    auto text = getMessageText();
    logger.push(journal::Message { text, level });
}

int main(int argc, const char* argv[]) {
    auto file_name = getFileName(argc, argv);
    auto base_level = getBaseLevel(argc, argv);

    ThreadSafeJournal logger(file_name, base_level);

    std::thread logger_thread(writeMessage, std::ref(logger));

    ApplicationCommands app;
    app.addCommand(Command { "Exit", [&](ApplicationCommands& app) { app.stop(); } });
    app.addCommand(Command { "Write message",
                             [&](ApplicationCommands& app) { getMessage(logger); } });

    app.start();

    logger.close();

    logger_thread.join();
}
