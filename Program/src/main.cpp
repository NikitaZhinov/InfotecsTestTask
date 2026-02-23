#include <iostream>
#include <istream>
#include <thread>

#include <journal/journal.hpp>

#include "thread-safe-logger.hpp"

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
    switch (argc) {
        case 1:
        case 2:
            return journal::UNIMPORTANT;

        default:
            break;
    }

    return journal::formatLevel(argv[2]);
}

static void writeMessage(ThreadSafeLogger& logger) {
    while (logger.isActive()) {
        logger.print();
    }
}

static journal::Level getLevelMessage() {
    std::cout << "Enter the importance level: ";

    std::string level_str;
    std::cin >> level_str;

    return journal::formatLevel(level_str);
}

static std::string getTextMessage() {
    std::cout << "Enter the text: ";

    std::string text;
    std::getline(std::cin >> std::ws, text);

    return text;
}

static void getMessage(ThreadSafeLogger& logger) {
    auto level = getLevelMessage();
    auto text = getTextMessage();
    logger.push(journal::Message { text, level });
}

int main(int argc, const char* argv[]) {
    auto file_name = getFileName(argc, argv);
    auto base_level = getBaseLevel(argc, argv);

    ThreadSafeLogger logger(file_name, base_level);

    std::thread logger_thread(writeMessage, std::ref(logger));

    bool run_flag = true;
    while (run_flag) {
        std::cout << "Chose the command:\n";
        std::cout << "[1] Write message\n";
        std::cout << "[0] Exit\n";

        int n = -1;
        std::cin >> n;

        std::cout << '\n';

        switch (n) {
            case 0:
                run_flag = false;
                break;

            case 1:
                getMessage(logger);
                break;

            default:
                std::cout << "Undefined command!\n";
                break;
        }

        std::cout << '\n';
    }

    logger.close();

    logger_thread.join();
}
