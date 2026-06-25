// WAP to covert integer to Roman number

#include <iostream>
using namespace std;

void intToRoman(int num) {
    int values[] = {1000, 900, 500, 400, 100, 90,
                    50,  40,  10, 9,   5,  4,   1};
    string symbols[] = {
        "M", "CM", "D", "CD", "C", "XC",
        "L", "XL", "X", "IX", "V", "IV", "I"};

    cout << "Roman numeral: ";
    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            cout << symbols[i];
            num -= values[i];
        }
    }
    cout << endl;
}

int main() {
    int number;
    cout << "Enter an integer (1-3999): ";
    cin >> number;

    if (number < 1 || number > 3999) {
        cout << "Invalid input. Please enter a number between 1 and 3999." << endl;
    } else {
        intToRoman(number);
    }

    return 0;
}
