cmake_minimum_required(VERSION 3.5)

add_compile_options(-O2 -g -Wall -Wextra -ansi -pedantic -Wconversion -Werror -std=gnu++11)

add_executable(ptgen Source/main.cpp Source/Options.cpp Source/Phonet.cpp Source/Phoneme.cpp Source/PhonemePool.cpp Source/utility.cpp)
