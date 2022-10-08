## libcli

Simple and lightweight library for C++ cli's

#### Example:
```c++
#include <iostream>
#include <libcli/libcli.h>

using namespace libcli;

int main() {
    Cli cli;
    auto firstMenu = cli.CreateMenu("first");
    auto secondMenu = cli.CreateMenu("second");
    
    firstMenu.AddCommand("say", "<text>", "Say command", [](const auto& args) {
        for (const auto& arg : args) {
            std::cout << arg << " ";
        }

        std::cout << std::endl;
    });
    
    firstMenu.AddCommand("secondMenu", "", "Select second menu", [&cli](const auto& args) {
        cli.SelectMenu("second");
    });

    secondMenu.AddCommand("firstMenu", "", "Select first menu", [&cli](const auto& args) {
        cli.SelectMenu("first");
    });

    cli.Start();

    return 0;
}
```

#### Add libcli in CMake:
```cmake
include(FetchContent)

FetchContent_Declare(libcli
        GIT_REPOSITORY https://github.com/ya-ilya/libcli
        GIT_TAG origin)
FetchContent_MakeAvailable(libcli)

target_link_libraries(${PROJECT_NAME} PRIVATE libcli::libcli)
```