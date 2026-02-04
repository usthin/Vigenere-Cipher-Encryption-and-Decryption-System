# Vigenère Cipher – C++ Implementation

This project implements a **Vigenère encryption and decryption system** in C++.
It supports both a **basic alphabet-only mode** and an **advanced ASCII mode**.

## 📌 Features

- User input for plaintext and encryption key
- Vigenère encryption and decryption
- **Basic mode**
    - Encrypts alphabetic characters only (A–Z)
    - Non-letter characters remain unchanged
- **Advanced mode**
    - Encrypts characters in the ASCII range 32–126
- Correct decryption back to the original plaintext
- Clear, modular, and readable C++ code

## 🛠 How It Works

### Basic Mode
- Uses the English alphabet (A–Z)
- The key is repeated to match the number of letters in the plaintext
- Encryption and decryption use modulo 26 arithmetic

### Advanced Mode
- Uses ASCII values from 32 to 126
- Encryption shifts characters based on key character ASCII values
- Supports symbols, numbers, and punctuation

## ▶ How to Run

1. Compile the program:
   ```bash
   g++ main.cpp -o vigenere
