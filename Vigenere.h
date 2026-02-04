#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>

// Constants
extern const std::string ALPHABET;
extern const int ASCII_START;
extern const int ASCII_END;

// Basic mode
std::string encryptBasic(const std::string& plaintext, const std::string& key);
std::string decryptBasic(const std::string& ciphertext, const std::string& key);

// Advanced ASCII mode
std::string encryptASCII(const std::string& plaintext, const std::string& key);
std::string decryptASCII(const std::string& ciphertext, const std::string& key);

#endif
