/*Problem Statement



To help Alice, a new property owner in a city, calculate the property tax, let's create a simple program. 



Implement a call-by-value function that takes the assessed value as an input argument. The function should determine the taxable amount by subtracting 8% from the assessed value and also calculate the property tax by applying a tax rate of 1.05% to the taxable amount.



Function Specifications: void propertyTaxCalc(double)

Input format :
The input consists of a double value that represents the assessed value.

Output format :
The first line of output displays "Taxable Amount: " followed by a double value, representing the taxable amount with two decimal places.

The second line displays "Property Tax: " followed by a double value, representing the property tax with two decimal places.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

105.00 ≤ Assessed value ≤ 106.00

Sample test cases :
Input 1 :
200000.88
Output 1 :
Taxable Amount: 184000.81
Property Tax: 1932.01
Input 2 :
987500.49
Output 2 :
Taxable Amount: 908500.45
Property Tax: 9539.25
*/



// You are using GCC
#include<stdio.h>
void propertyTaxCalc(double n){
    double tax,prop_tax;
    tax=n-n*0.08;
    prop_tax=tax*0.0105;
    printf("Taxable Amount: %.2lf \n",tax);
    printf("Property Tax: %.2lf",prop_tax);
}
int main(){
    double n;
    scanf("%lf",&n);
    propertyTaxCalc(n);
}