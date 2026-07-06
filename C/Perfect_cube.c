// // // You are using GCC
// // #include<stdio.h>
// // #include<math.h>
// // int main(){
// //     int n;
// //     scanf("%d",&n);
// //     for(int i=1;i<n;i++){
// //         if(cbrt(n)!=pow(i,3)){
// //             printf("%d  %.1lf  %.1lf    ",i,cbrt(n),pow(i,3));
// //         }
// //     }
// // }


// // You are using GCC
// #include<stdio.h>
// #include<math.h>
// int v;
// int isPerfectCube(double n){
//     for(double i=1;i<=n;i++){
//         if(i==cbrt(n)){
//             return v=1;
//             break;
//         }
//     }
// }
// int main(){
//     int n;
//     scanf("%d",&n);
//     if(v=1){
//         printf("Perfect cube");
//     }
//     else{
//         printf("Not a perfect cube");
//     }
// }







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