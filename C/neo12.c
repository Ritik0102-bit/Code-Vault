/*
Problem Statement



In a hexagonal garden, each side measures a certain length. Write a program that takes the side length as input and calculates both the area and perimeter of the hexagonal garden. 



Formulas Used:

Area of a hexagon = a2 * 3.0 * ((√3.0)/2.0)
Perimeter of a hexagon = 6.0 * a, where a is the side length.


Note: The power is calculated using pow() function and the square root is calculated using sqrt() from the math library.

Input format :
The input consists of a double-value a, representing the side length of a hexagonal garden.

Output format :
The first line of output prints "Area: " followed by a double value, representing the area of the hexagonal garden, rounded to two decimal places.

The second line prints "Perimeter: " followed by a double value, representing the perimeter of the hexagonal garden, rounded to two decimal places.



Refer to the sample output for formatting specifications.

Code constraints :
In the given scenario, the test cases fall under the following constraints:

1.00 ≤ a ≤ 50.00

Sample test cases :
Input 1 :
1.78
Output 1 :
Area: 8.23
Perimeter: 10.68
Input 2 :
6.25
Output 2 :
Area: 101.49
Perimeter: 37.50
Input 3 :
49.65
Output 3 :
Area: 6404.58
Perimeter: 297.90
*/



// You are using GCC
#include<stdio.h>
#include<math.h>
int main(){
    double n;
    scanf("%lf",&n);
    double area,peri;
    area=pow(n,2)*3.0*((sqrt(3.0))/2.0);
    peri=6.0*n;
    printf("Area: %.2lf",area);
    printf("\nPerimeter: %.2lf",peri);
}