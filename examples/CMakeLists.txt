cmake_minimum_required(VERSION 3.5)

add_executable(fvadwav fvadwav.c)
target_link_libraries(fvadwav sndfile fvad)
install(TARGETS fvadwav DESTINATION bin)
