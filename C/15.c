#include<stdio.h>
int area(int n){
    int a,r,l,w,b,h,d1,d2;
    switch(n){
        case 1:
        printf("Enter the side of Square:");
        scanf("%d",&a);
        printf("Area of square is: %d",a*a);
        break;
        case 2:
        printf("Enter the sides of Rectangle:");
        scanf("%d%d",&l,&w);
        printf("Area of square is: %d",a*a);
        break;
        case 3:
        printf("Enter the side of Square:");
        scanf("%d",&a);
        printf("Area of square is: %d",a*a);
        break;
        case 4:
        printf("Enter the radius: ");
        scanf("%d",&r);
        printf("area of circle: %f",2*3.14*r);
        break;
        case 5:
        printf("Enter the side of Square:");
        scanf("%d",&a);
        printf("Area of square is: %d",a*a);
        break;
    }
}
int main(){
    int n;
    printf("1.Square\n2.Rectangle\n3.Triangle\n4.Circle\n5.Rhombus");
    printf("Enter you choice to find area: ");
    scanf("%d",&n);
    area(n);
}