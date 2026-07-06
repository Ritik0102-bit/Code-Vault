// WAP to covert integer to Roman number

#include <stdio.h>

void intToRoman(int num) {
    // Arrays for storing Roman numeral values and symbols
    int values[] = {1000, 900, 500, 400, 100, 90,  50,  40,  10, 9,   5,  4,  1};
    char *symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    printf("Roman numeral: ");
    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            printf("%s", symbols[i]);
            num -= values[i];
        }
    }
    printf("\n");
}

int main() {
    int number;
    printf("Enter an integer (1-3999): ");
    scanf("%d", &number);

    if (number < 1 || number > 3999) {
        printf("Invalid input. Please enter a number between 1 and 3999.\n");
    } else {
        intToRoman(number);
    }

    return 0;
}
