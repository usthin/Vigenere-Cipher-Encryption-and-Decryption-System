#include <iostream>
#include "Vigenere.h"

using namespace std;

int main() {2
    int mode, operation;
    string text, key;

    cout << "Vigenere Cipher System\n\n";
    cout << "Select Mode:\n";
    cout << "1 - Basic Mode (Alphabet Only)\n";
    cout << "2 - Advanced Mode (ASCII 32–126)\n";
    cout << "Choice: ";
    cin >> mode;
    cin.ignore();

    cout << "\nSelect Operation:\n";
    cout << "1 - Encrypt Only\n";
    cout << "2 - Decrypt Only\n";
    cout << "3 - Encrypt and Decrypt\n";
    cout << "Choice: ";
    cin >> operation;
    cin.ignore();

    cout << "\nEnter text: ";
    getline(cin, text);

    cout << "Enter key: ";
    getline(cin, key);

    cout << endl;

    if (mode == 1) {
        if (operation == 1) {
            cout << "Encrypted Text: "
                 << encryptBasic(text, key) << endl;
        }
        else if (operation == 2) {
            cout << "Decrypted Text: "
                 << decryptBasic(text, key) << endl;
        }
        else if (operation == 3) {
            string encrypted = encryptBasic(text, key);
            string decrypted = decryptBasic(encrypted, key);

            cout << "Encrypted Text: " << encrypted << endl;
            cout << "Decrypted Text: " << decrypted << endl;
        }
    }
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
        cout << "Invalid selection.\n";
    }

    return 0;
}
