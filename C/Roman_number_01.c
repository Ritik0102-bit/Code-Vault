// WAP to covert Roman number to integer

#include <stdio.h>
#include <string.h>

int value(char r) {
    switch (r) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(char *s) {
    int total = 0;
    int prev = 0;

    for (int i = strlen(s) - 1; i >= 0; i--) {
        int curr = value(s[i]);
        if (curr < prev)
            total -= curr;
        else
            total += curr;
        prev = curr;
    }
    return total;
}

int main() {
    char roman[20];
    printf("Enter a Roman numeral (in uppercase): ");
    scanf("%s", roman);
    int result = romanToInt(roman);
    printf("Integer: %d\n", result);
    return 0;
}
