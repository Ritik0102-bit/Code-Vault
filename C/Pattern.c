// Pattern 1

// #include<stdio.h>
// int main(){
//     int i,j;
//     for(i=1;i<=5;i++){
//         for(j=1;j<=i;j++){
//             printf("*\t");
//         }
//         printf("\n");
//     }
// }


// Pattern 2

// #include<stdio.h>
// int main(){
//     int i,j;
//     for(i=1;i<=5;i++){
//         for(j=5;i<=j;j--){
//             printf("*\t");
//         }
//         printf("\n");
//     }
// }


// Pattern 3

// #include<stdio.h>
// int main(){
//     int i,j;
//     for(i=1;i<=5;i++){
//         for(j=1;j<=i;j++){
//             printf("%d\t",j);
//         }
//         printf("\n");
//     }
// }


// Pattern 4

// #include<stdio.h>
// int main(){
//     int i,j;
//     for(i=1;i<=5;i++){
//         for(j=1;j<=i;j++){
//             printf("%d\t",i);
//         }
//         printf("\n");
//     }
// }


// Pattern 5

// #include<stdio.h>
// int main(){
//     int i,j;
//     char c='A';
//     for(i=1;i<=5;i++ && c++){
//         for(j=1;j<=i;j++){
//             printf("%c\t",c);
//         }
//         printf("\n");
//     }
// }


// Pattern 6

#include<stdio.h>
int main(){
    int i,j;
    char c='A';
    for(i=1;i<=5;i++){
        for(j=1;j<=i;j++ && c++){
            printf("%c\t",c);
        }
        printf("\n");
    }
}
