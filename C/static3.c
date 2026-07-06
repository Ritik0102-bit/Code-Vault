/*
Problem Statement



Styles needs to find the first repeated digit in an integer. He needs a program that checks for repeated digits and displays the first repeated digit it encounters. If there are no repeated digits, a warning message must be displayed accordingly. 



Help him with the code that uses a while loop.

Input format :
The input consists of an integer n, which represents the input number.

Output format :
The output displays "First repeated digit: " followed by the first repeated digit found in n.

If there are no repeated digits in n, the output displays "No repeated digits found."



Refer to the sample output for formatting specifications.

Code constraints :
In the given scenario, the test cases fall under the following constraints:

100 ≤ n < 109

Sample test cases :
Input 1 :
2256
Output 1 :
First repeated digit: 2
Input 2 :
23423
Output 2 :
First repeated digit: 2
Input 3 :
12354
Output 3 :
No repeated digits found.

*/



#include <stdio.h>

int main() {    int n, digit, temp, reversed = 0,rem=0;
       scanf("%d", &n);
    // Reverse the number first
    while (n > 0) 
    {
        int rem=n % 10;
        reversed = reversed * 10 + rem;
        n /= 10;
    }
    // Now, process the reversed number
    while (reversed > 0) 
    {
        digit = reversed % 10;
        reversed =reversed/ 10;
        temp = reversed;
        
        while (temp > 0) 
        {
            if (temp % 10 == digit) 
            {
                printf("First repeated digit: %d\n", digit);
                return 0;
            }
            temp =temp/ 10;
        }
    }
    printf("No repeated digits found.\n");
    return 0; }