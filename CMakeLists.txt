cmake_minimum_required(VERSION 3.29)
project(Vigenere_Encryption_and_Decryption_System)

set(CMAKE_CXX_STANDARD 26)

add_executable(Vigenere_Encryption_and_Decryption_System main.cpp
        Vigenere.h
        Vigenere.cpp)
