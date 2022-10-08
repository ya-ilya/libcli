#ifndef LIBCLI_CLI_H
#define LIBCLI_CLI_H

#include <iostream>
#include <regex>
#include "Menu.h"

namespace libcli {
    class Cli {
    private:
        std::vector<std::reference_wrapper<Menu>> menus;
        std::string current;
    public:
        std::string prefix = "%menu%> ";
        bool started = false;

        Cli() = default;

        Menu CreateMenu(const std::string& name);

        void SelectMenu(const std::string& name);

        void DeleteMenu(const std::string& name);

        void Start();

        inline void Stop();
    };
}

#endif //LIBCLI_CLI_H
