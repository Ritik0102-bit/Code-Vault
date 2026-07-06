// Problem statement



// Write a program to determine the speeding fine for a driver. Take input for the driver's speed and the speed limit. Calculate the fine based on the exceeding speed, applying a standard rate of 5 per unit over the speed limit. 



// Double the fine if the speed exceeds the limit by 15 or more units, and add an amount of 30 if the speed exceeds the limit by 10 to 14 units. If the driver is within the speed limit, print "No fine".

// Input format :
// The first line contains an integer value 'n', representing the driver's speed.

// The second line contains an integer value 'n1' representing the speed limit in the area.

// Output format :
// If the driver does not exceed the speed limit, the program outputs "No fine".

// Otherwise, the output displays the calculated fine as an integer.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n ≤ 100

// 1 ≤ n1 ≤ 75

// Sample test cases :
// Input 1 :
// 80
// 60
// Output 1 :
// 200
// Input 2 :
// 63
// 50
// Output 2 :
// 95
// Input 3 :
// 45
// 40
// Output 3 :
// 25
// Input 4 :
// 45
// 50
// Output 4 :
// No fine



// You are using GCC
#include<stdio.h>
int main(){
    int n,n1;
    scanf("%d",&n);
    scanf("%d",&n1);
    int diff=n-n1;
    int fine=diff*5;
    if(n<=n1){
    printf("No fine");
    }
    else if(1<=diff && diff<10){
    printf("%d",fine);
    }
    else if(10<=diff && diff<=14){
    printf("%d",30+fine);
    }
    else{
    printf("%d",fine*2);
    }
}