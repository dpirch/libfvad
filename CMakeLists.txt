cmake_minimum_required(VERSION 3.5)
project(libfvad VERSION 1.0.1 LANGUAGES C)

include_directories(include)
add_subdirectory(src)
install(DIRECTORY include DESTINATION .)

