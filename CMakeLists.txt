cmake_minimum_required(VERSION 3.5)

add_compile_options(-O2 -g -Wall -Wextra -ansi -pedantic -Wconversion -Werror -std=gnu++11)

add_executable(ptgen src/main.cpp src/Options.cpp src/Phonet.cpp src/Phoneme.cpp src/PhonemePool.cpp src/utility.cpp)
