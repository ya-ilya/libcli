#ifndef LIBCLI_COMMAND_H
#define LIBCLI_COMMAND_H

#include <iostream>
#include <vector>
#include <functional>

namespace libcli {
    class Command {
    public:
        std::string name;
        std::string usage;
        std::string description;
        int argumentsCount = 0;
        std::function<void(std::vector<std::string>)> execute;

        Command(const std::string& name, const std::string& usage, const std::string& description,
                const std::function<void(std::vector<std::string>)>& execute);
    };
}

#endif //LIBCLI_COMMAND_H
