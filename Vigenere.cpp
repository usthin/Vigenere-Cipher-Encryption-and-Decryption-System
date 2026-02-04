#include "Vigenere.h"
#include <cctype>

const std::string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int ASCII_START = 32;
const int ASCII_END = 126;

/* ================= BASIC MODE ================= */

std::string generateKey(const std::string& text, const std::string& key) {
    std::string fullKey;
    int keyIndex = 0;

    for (char c : text) {
        if (isalpha(c)) {
            fullKey += toupper(key[keyIndex % key.length()]);
            keyIndex++;
        } else {
            fullKey += c;
        }
    }
    return fullKey;
}

std::string encryptBasic(const std::string& plaintext, const std::string& key) {
    std::string ciphertext;
    std::string fullKey = generateKey(plaintext, key);

    for (size_t i = 0; i < plaintext.length(); i++) {
        if (isalpha(plaintext[i])) {
            int p = toupper(plaintext[i]) - 'A';
            int k = fullKey[i] - 'A';
            ciphertext += ALPHABET[(p + k) % 26];
        } else {
            ciphertext += plaintext[i];
        }
    }
    return ciphertext;
}

std::string decryptBasic(const std::string& ciphertext, const std::string& key) {
    std::string plaintext;
    std::string fullKey = generateKey(ciphertext, key);

    for (size_t i = 0; i < ciphertext.length(); i++) {
        if (isalpha(ciphertext[i])) {
            int c = ciphertext[i] - 'A';
            int k = fullKey[i] - 'A';
            plaintext += ALPHABET[(c - k + 26) % 26];
        } else {
            plaintext += ciphertext[i];
        }
    }
    return plaintext;
}

/* ================= ASCII MODE ================= */

std::string encryptASCII(const std::string& plaintext, const std::string& key) {
    std::string ciphertext;
    int keyIndex = 0;
    int range = ASCII_END - ASCII_START + 1;

    for (char c : plaintext) {
        if (c >= ASCII_START && c <= ASCII_END) {
            int shift = key[keyIndex % key.length()];
            char encrypted = ASCII_START +
                ((c - ASCII_START + shift) % range);
            ciphertext += encrypted;
            keyIndex++;
        } else {
            ciphertext += c;
        }
    }
    return ciphertext;
}

std::string decryptASCII(const std::string& ciphertext, const std::string& key) {
    std::string plaintext;
    int keyIndex = 0;
    int range = ASCII_END - ASCII_START + 1;

    for (char c : ciphertext) {
        if (c >= ASCII_START && c <= ASCII_END) {
            int shift = key[keyIndex % key.length()];
            char decrypted = ASCII_START +
                ((c - ASCII_START - shift + range) % range);
            plaintext += decrypted;
            keyIndex++;
        } else {
            plaintext += c;
        }
    }
    return plaintext;
}
