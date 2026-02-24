#pragma once

#include <functional>
#include <string>
#include <vector>

class ApplicationCommands;

/**
 * @brief Presentation of the application command.
 */
class Command {
public:
    using func_signature = std::function<void(ApplicationCommands&)>;

private:
    std::string name_;
    func_signature func_;

public:
    /**
     * @brief Construct a new Command object
     *
     * @param name command name
     * @param func what the command does
     */
    Command(const std::string& name, const func_signature& func);

    /**
     * @brief Call the command.
     *
     * @param app current application
     */
    void operator()(ApplicationCommands& app);

    /**
     * @brief Get the command name
     *
     * @return std::string
     */
    std::string getName() const;
};

/**
 * @brief Presentation of a multifunctional application.
 */
class ApplicationCommands {
    std::vector<Command> commands_;
    bool is_run_ = false;

public:
    /**
     * @brief Add a new command.
     *
     * @param cmd a new command.
     */
    void addCommand(const Command& cmd);

    /**
     * @brief Start the application.
     */
    void start();

    /**
     * @brief Stop the application.
     */
    void stop();
};
