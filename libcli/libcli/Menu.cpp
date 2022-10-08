#include "../../include/libcli/Menu.h"

libcli::Menu::Menu(const std::string& name) {
    this->name = name;

    AddCommand("help", "", "List of all commands in this menu", [this](const auto& args) {
        for (const auto& command : commands) {
            std::cout << ": " << command.name;

            if (!command.usage.empty()) {
                std::cout << " " << command.usage;
            }

            std::cout << " - " << command.description << std::endl;
        }
    });
}

void libcli::Menu::AddCommand(const std::string& commandName, const std::string& usage, const std::string& description,
                              const std::function<void(std::vector<std::string>)>& execute) {
    commands.emplace_back(commandName, usage, description, execute);
}

void libcli::Menu::DeleteCommand(const std::string& commandName) {
    commands.erase(std::remove_if(commands.begin(), commands.end(), [&commandName](const auto& command) {
        return command.name == commandName;
    }), commands.end());
}

void libcli::Menu::TryExecute(const std::vector<std::string>& args) {
    for (const auto& command : commands) {
        if (command.name == args[0]) {
            if (command.argumentsCount > args.size() - 1) {
                std::cout << "Not enough arguments, correct usage is - " << command.name;

                if (!command.usage.empty()) {
                    std::cout << " " << command.usage;
                }

                std::cout << std::endl;
                return;
            }

            try {
                std::vector<std::string> argsWithoutLabel;

                for (int i = 1; i < args.size(); ++i) {
                    argsWithoutLabel.push_back(args[i]);
                }

                command.execute(argsWithoutLabel);
            } catch (std::exception& ex) {
                std::cout << "E: " << ex.what() << std::endl;
            }

            break;
        }
    }
}
