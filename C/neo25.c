/*
Problem Statement



Ravi is learning how to use the register storage class in C. To practice, Ravi has to write a program that calculates the area and perimeter of a trapezoid. A trapezoid has two parallel sides (bases) and two non-parallel sides (legs). Ravi needs your help to store these variables in register memory to speed up the computation.



The formula for calculating the area of a trapezoid is:



a and b are the lengths of the two parallel sides (bases).

h is the height (the perpendicular distance between the parallel sides).



The formula for calculating the perimeter of a trapezoid is:

Perimeter = a+b+c+d

a and b are the lengths of the parallel sides (bases).

c and d are the lengths of the non-parallel sides (legs).

Input format :
The first line contains an integer a , representing the length of the first parallel side.

The second line contains an integer b , representing the length of the second parallel side.

The third line contains an integer h , representing the height of the trapezoid.

The fourth line contains an integer c , representing the length of the first non-parallel side (leg).

The fifth line contains an integer d , representing the length of the second non-parallel side (leg).

Output format :
The output displays Area: <area_value> , Perimeter: <perimeter_value> in separate lines

Where:

<area_value> is the calculated area of the trapezoid, rounded to two decimal places.

<perimeter_value> is the calculated perimeter of the trapezoid, an integer.

Code constraints :
1 ≤ a, b, c, d, h ≤ 1000

Sample test cases :
Input 1 :
5
7
3
4
6
Output 1 :
Area: 18.00
Perimeter: 22
Input 2 :
10
20
5
8
6
Output 2 :
Area: 75.00
Perimeter: 44

*/




// You are using GCC
#include<stdio.h>
int main(){
    int a,b,h,c,d;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&h);
    scanf("%d",&c);
    scanf("%d",&d);
    float area=((a+b)/2.0)*h;
    int peri=a+b+c+d;
    printf("Area: %.2f\n",area);
    printf("Perimeter: %d",peri);
}