cmake_minimum_required(VERSION 3.17)

target_include_directories(${PROJECT_NAME} PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

target_sources(${PROJECT_NAME} PRIVATE
        libcli/libcli.h
        libcli/Cli.h
        libcli/Command.h
        libcli/Menu.h)

# libcli - Name of headers directory
install(DIRECTORY libcli DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
