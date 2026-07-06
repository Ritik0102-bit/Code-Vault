/*
Problem Statement



Jessi wants to write a program where a recursive function, recursiveFunc, is called with an input integer n. Inside the function, a local variable m is initialized to 3 using the auto keyword. The program prints the value of m before and after each recursive call. 



The input integer n is obtained from the user in the main function.

Input format :
The input consists of an integer n.

Output format :
The output prints the value of the variable m before and after each recursive call from n to 0:

The format for before call: "Before call(x): m" where x is the number of the particular call.

The format for after call: "After return(x): m" where x is the number of the particular call.



Refer to the sample output for the formatting specifications.

Code constraints :
In the given scenario, the test cases fall under the following constraints:

1 ≤ n ≤ 10

Sample test cases :
Input 1 :
2
Output 1 :
Before call(2): 3
Before call(1): 3
Before call(0): 3
After return(0): 3
After return(1): 3
After return(2): 3
Input 2 :
3
Output 2 :
Before call(3): 3
Before call(2): 3
Before call(1): 3
Before call(0): 3
After return(0): 3
After return(1): 3
After return(2): 3
After return(3): 3
*/



// You are using GCC
#include<stdio.h>
void recursiveFunc(int n){
    auto m=3;
    printf("Before call(%d): %d\n",n,m);
    if(n>0){
        recursiveFunc(n-1);
    }
    printf("After return(%d): %d\n",n,m);
}
int main(){
    int n;
    scanf("%d",&n);
    recursiveFunc(n);
}