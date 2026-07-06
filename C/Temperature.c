// WAP to convert temperature from degree Celsius to degree Fahrenheit and vice-versa

#include <stdio.h>
int main()
{
    float c,f,f1,c1;
    printf("\nEnter temperature in degree celsius:");
    scanf("%f",&c);
    f=(c*9.0/5.0)+32.0;
    printf("\n Temperature in Fahrenheit is:%f",f);
    printf("\nEnter temperature in Fahrenheit:");
    scanf("%f",&f1);
    c1=(f1-32.0)*5.0/9.0;
    printf("\nTemperature in degree celcius is:%f",c1);
    return 0;
}
