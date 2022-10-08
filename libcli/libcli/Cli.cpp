#include "../../include/libcli/Cli.h"

libcli::Menu libcli::Cli::CreateMenu(const std::string& name) {
    Menu menu(name);

    if (menus.empty()) {
        current = menu.name;
    }

    menus.emplace_back(menu);
    return menu;
}

void libcli::Cli::SelectMenu(const std::string& name) {
    current = name;
}

void libcli::Cli::DeleteMenu(const std::string& name) {
    menus.erase(std::remove_if(menus.begin(), menus.end(), [&name](const auto& menu) {
        return menu.get().name == name;
    }), menus.end());
}

void libcli::Cli::Start() {
    started = true;

    while (started) {
        std::cout << current << "> ";
        std::string input;
        std::getline(std::cin, input);
        std::vector<std::string> args;

        char *token = std::strtok((char *) (input.c_str()), " ");
        while (token != nullptr) {
            args.emplace_back(token);
            token = std::strtok(nullptr, " ");
        }

        if (args.empty()) {
            continue;
        }

        if (args[0] == "exit") {
            Stop();
            continue;
        }

        for (const auto& menu : menus) {
            if (menu.get().name == current) {
                menu.get().TryExecute(args);
                break;
            }
        }
    }
}

void libcli::Cli::Stop() {
    started = false;
}
