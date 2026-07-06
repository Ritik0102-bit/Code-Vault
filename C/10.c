#include<stdio.h>
//Switch 

int main(){
    char day;
    printf("enter day(1-7): ");
    scanf("%s",&day);

    switch (day)
    {
    case 'm': printf("Monday \n");
        break;
    case 't': printf("Tuesday \n");
        break;
    case 'w': printf("Wednesday \n");
        break;
    case 'T': printf("Thursday \n");
        break;
    case 'f': printf("Friday \n");
        break;
    case 's': printf("Saturday \n");
        break;
    case 'S': printf("Sunday \n");
        break;
    default: printf("Not a valid day");
    }
}