/*
Problem Statement



George, a secret agent, needs a program to encrypt a character using a shifting method. The program should prompt him to enter an alphabet and a shift amount as register storage class inputs. 



The encrypted character is obtained by shifting the input alphabet by the specified amount in a circular manner. Uppercase and lowercase letters wrap around, ensuring a seamless shift within the alphabet.



Example: If the character 'y' wants to be rotated 6 times, it wraps around the alphabet after reaching 'z', and the shifting process results in the output 'e'.

Input format :
The input consists of a character c representing the alphabet on which shifting happens and an integer n representing the number of times it has to be shifted, separated by a space.

Output format :
The output prints the character after shifting the input alphabet (to its right) n times.

If c is not an alphabet, the output prints the input character as such without shifting.



Refer to the sample output for the formatting specifications.

Code constraints :
c should be a valid ASCII character.

1 ≤ n ≤ 20

Sample test cases :
Input 1 :
A 1
Output 1 :
B
Input 2 :
Z 2
Output 2 :
B
Input 3 :
c 4
Output 3 :
g
Input 4 :
# 5
Output 4 :
#
*/



// The given problem requires shifting a character in the alphabet circularly based on an input integer shift value. The code provided has an issue in handling the circular shifting correctly, as it directly adds n to c without considering wrap-around behavior.

// Corrected Code:

#include <stdio.h>

int main() {
    char c;
    int n;
    scanf(" %c %d", &c, &n);

    if (c >= 'A' && c <= 'Z') {
        c = 'A' + (c - 'A' + n) % 26;
    } else if (c >= 'a' && c <= 'z') {
        c = 'a' + (c - 'a' + n) % 26;
    }

    printf("%c\n", c);
    return 0;
}

/*Explanation:

1. The program takes a character and an integer shift value as input.


2. It checks whether the character is an uppercase or lowercase letter.


3. The shifting is done within the range of uppercase (A-Z) or lowercase (a-z), ensuring wrap-around using modulo arithmetic.


4. The modified character is printed as output.



Would you like further modifications or explanations?
*/