#ifndef LIBCLI_MENU_H
#define LIBCLI_MENU_H

#include <iostream>
#include <algorithm>
#include "Command.h"

namespace libcli {
    class Menu {
    public:
        std::string name;
        std::vector<Command> commands;

        Menu() = default;

        explicit Menu(const std::string& name);

        void AddCommand(const std::string& commandName, const std::string& usage, const std::string& description,
                        const std::function<void(std::vector<std::string>)>& execute);

        void DeleteCommand(const std::string& commandName);

        void TryExecute(const std::vector<std::string>& args);
    };
}

#endif //LIBCLI_MENU_H
