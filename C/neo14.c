/*
Problem Statement



Ruby, a mathematician, is exploring cubic numbers in a series. Develop a recursive function isPerfectCube to help Ruby check if a given number is a perfect cube. 



A perfect cube is an integer that can be expressed as the cube of another integer. For example, 1, 8, 27, 64 and 125 are perfect cubes because they can be expressed as 13, 23, 33, 43 and 53 respectively.

Input format :
The input consists of an integer n, representing the number Ruby wants to check.

Output format :
The output prints "Perfect cube" if n is a perfect cube number.

Otherwise, the output prints "Not a perfect cube".



Refer to the sample output for the formatting specifications.

Code constraints :
In the given scenario, the test cases fall under the following constraints:

2 ≤ n ≤ 1000

Sample test cases :
Input 1 :
8
Output 1 :
Perfect cube
Input 2 :
122
Output 2 :
Not a perfect cube
*/



// You are using GCC
#include<stdio.h>
#include<math.h>
int isPerfectCube(int n){
    int cuberoot=cbrt(n);
        return (cuberoot*cuberoot*cuberoot==n);
}
int main(){
    int n;
    scanf("%d",&n);
    if(isPerfectCube(n)){
        printf("Perfect cube");
    }
    else{
        printf("Not a perfect cube");
    }
}














//Method 2

#include <stdio.h>

// Recursive function to check if n is a perfect cube
int isPerfectCube(int n, int i) {
    // Base cases
    if (i * i * i == n)
        return 1;  // True
    if (i * i * i > n)
        return 0;  // False
    
    // Recursive case
    return isPerfectCube(n, i + 1);
}

int main() {
    int n;
    
    // Input
    printf("Enter a number: ");
    scanf("%d", &n);
    
    // Output
    if (isPerfectCube(n, 1))
        printf("Perfect cube\n");
    else
        printf("Not a perfect cube\n");
    
    return 0;
}