cmake_minimum_required(VERSION 3.5)
project(libfvad VERSION 1.0.1 LANGUAGES C)

option(ENABLE_EXAMPLES "build the fvadwav example program; requires libsndfile" OFF)

include_directories(include)
add_subdirectory(src)
if(${ENABLE_EXAMPLES})
    add_subdirectory(examples)
endif()

install(DIRECTORY include DESTINATION .)
