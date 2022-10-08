#include "../../include/libcli/Command.h"

libcli::Command::Command(const std::string& name, const std::string& usage, const std::string& description,
                         const std::function<void(std::vector<std::string>)>& execute) {
    this->name = name;
    this->usage = usage;
    this->description = description;
    this->execute = execute;

    bool readArgument;
    for (auto const ch : usage) {
        if (ch == '<') {
            readArgument = true;
        } else if (ch == '>' && readArgument) {
            readArgument = false;
            argumentsCount++;
        }
    }
}
