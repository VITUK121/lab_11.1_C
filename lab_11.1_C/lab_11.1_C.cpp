#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

bool parseFile(char* t) {
    FILE* f;
    f = fopen(t, "r");

    if ((f == NULL)) {
        cout << "Error while opening file";
        return false;
    }

    char ch;
    int i = 0;
    char word[] = { 'w', 'h', 'i', 'l', 'e' };
    bool found[5] = { false, false, false, false, false };
    bool all_found = true;
    while ((ch = fgetc(f)) != EOF) {
        for (int i = 0; i < 5; i++) {
            if (ch == word[i]) {
                found[i] = true;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        if (!found[i]) {
            return false;
        }
    }

    fclose(f);
    return true;
}

char* string_to_char(string from_) {
    int len = from_.length();

    char* to_ = new char[len + 1];

    for (int i = 0; i < len; i++) {
        to_[i] = from_[i];
    }

    to_[len] = '\0';  

    return to_;
}

int main(){   
    string t;
    cout << "Enter filename: "; cin >> t;

    char* name = string_to_char(t);

    cout << "All letters from 'while' in file = " << ((parseFile(name) == true) ? ("True") : ("False"));
}
