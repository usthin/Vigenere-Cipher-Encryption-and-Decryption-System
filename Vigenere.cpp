#include "Vigenere.h"
#include <cctype>

// Alphabet used in basic mode
const std::string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// ASCII range for advanced mode
const int ASCII_START = 32;
const int ASCII_END = 126;

/* =====================================================
   BASIC MODE FUNCTIONS (Alphabet Only)
   ===================================================== */

// Generates a repeated key that matches the plaintext length
// Non-alphabetic characters are preserved
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

// Encrypts plaintext using the Vigenere cipher (A–Z)
std::string encryptBasic(const std::string& plaintext, const std::string& key) {
    std::string ciphertext;
    std::string fullKey = generateKey(plaintext, key);

    for (size_t i = 0; i < plaintext.length(); i++) {
        if (isalpha(plaintext[i])) {
            int p = toupper(plaintext[i]) - 'A';
            int k = fullKey[i] - 'A';
            ciphertext += ALPHABET[(p + k) % 26];
        } else {
            ciphertext += plaintext[i]; // Keep symbols unchanged
        }
    }
    return ciphertext;
}

// Decrypts ciphertext back to original plaintext
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

/* =====================================================
   ADVANCED MODE FUNCTIONS (ASCII 32–126)
   ===================================================== */

// Encrypts all printable ASCII characters
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

// Decrypts ASCII ciphertext back to original text
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
