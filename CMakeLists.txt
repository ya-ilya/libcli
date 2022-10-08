cmake_minimum_required(VERSION 3.20)
project(libcli)

set(CMAKE_STATIC_LIBRARY_PREFIX "")

if(${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")
    set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
    set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
else()
    if(CMAKE_CXX_STANDARD)
        set(PARENT_CXX_STANDARD ${CMAKE_CXX_STANDARD})
        message(STATUS "CXX standard of parent project: ${PARENT_CXX_STANDARD}")
    endif()
endif()

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(libcli) # .cpp files
add_subdirectory(include) # .h files
