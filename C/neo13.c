/*
Problem Statement



Given a range [n, m], find the count of elements that have an odd number of factors in the given range (n and m inclusive). Use mathematical library functions to solve the problem.



Examples



Input: n = 5, m = 100

Output: 8

Explanation: The numbers with odd factors between 5 and 100 are 9, 16, 25, 36, 49, 64, 81 and 100. Hence the output is 8.



Input: n = 8, m = 65

Output: 6

Explanation: The numbers with odd factors between 8 and 65 are 9, 16, 25, 36, 49, and 64. Hence the output is 6.

Input format :
The input consists of two space-separated integers n and m, representing the range.

Output format :
The output prints an integer, representing the count of elements that have an odd number of factors in the given range.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1 ≤ n, m ≤ 105

Sample test cases :
Input 1 :
5 100
Output 1 :
8
Input 2 :
8 120
Output 2 :
8
Input 3 :
8 65
Output 3 :
6

*/





//Method 1

// You are using GCC
#include<stdio.h>
#include<math.h>
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int count=floor(sqrt(m))-ceil(sqrt(n))+1;
    printf("%d",count);
}



//Method 2

#include <stdio.h>
#include <math.h>

// Function to count numbers with odd factors (i.e., perfect squares)
int countPerfectSquares(int n, int m) {
    int count = 0;
    for (int i = n; i <= m; i++) {
        int root = sqrt(i);
        if (root * root == i) {  // Check if perfect square
            count++;
        }
    }
    return count;
}

int main() {
    int n, m;

    // Input
    printf("Enter range (n m): ");
    scanf("%d %d", &n, &m);

    // Output
    printf("%d\n", countPerfectSquares(n, m));

    return 0;
}