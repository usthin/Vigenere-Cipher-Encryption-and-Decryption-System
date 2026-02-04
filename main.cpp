#include <iostream>
#include "Vigenere.h"

using namespace std;

int main() {
    int mode, operation;
    string text, key;

    // Program title
    cout << "Vigenere Cipher Encryption and Decryption System\n\n";

    // Select encryption mode
    cout << "Select Mode:\n";
    cout << "1 - Basic Mode (Alphabet Only)\n";
    cout << "2 - Advanced Mode (ASCII 32–126)\n";
    cout << "Choice: ";
    cin >> mode;
    cin.ignore(); // Clear input buffer

    // Select operation type
    cout << "\nSelect Operation:\n";
    cout << "1 - Encrypt Only\n";
    cout << "2 - Decrypt Only\n";
    cout << "3 - Encrypt and Decrypt (Reversible Test)\n";
    cout << "Choice: ";
    cin >> operation;
    cin.ignore(); // Clear input buffer

    // Get user input text
    cout << "\nEnter text: ";
    getline(cin, text);

    // Get encryption/decryption key
    cout << "Enter key: ";
    getline(cin, key);

    cout << endl;

    // BASIC MODE
    if (mode == 1) {
        if (operation == 1) {
            // Encrypt only
            cout << "Encrypted Text: "
                 << encryptBasic(text, key) << endl;
        }
        else if (operation == 2) {
            // Decrypt only
            cout << "Decrypted Text: "
                 << decryptBasic(text, key) << endl;
        }
        else if (operation == 3) {
            // Encrypt then decrypt to show reversibility
            string encrypted = encryptBasic(text, key);
            string decrypted = decryptBasic(encrypted, key);

            cout << "Encrypted Text: " << encrypted << endl;
            cout << "Decrypted Text: " << decrypted << endl;
        }
    }

    // ADVANCED ASCII MODE
    else if (mode == 2) {
        if (operation == 1) {
            cout << "Encrypted Text: "
                 << encryptASCII(text, key) << endl;
        }
        else if (operation == 2) {
            cout << "Decrypted Text: "
                 << decryptASCII(text, key) << endl;
        }
        else if (operation == 3) {
            string encrypted = encryptASCII(text, key);
            string decrypted = decryptASCII(encrypted, key);

            cout << "Encrypted Text: " << encrypted << endl;
            cout << "Decrypted Text: " << decrypted << endl;
        }
    }
    else {
        // Invalid menu selection
        cout << "Invalid selection. Please restart the program.\n";
    }

    return 0;
}
