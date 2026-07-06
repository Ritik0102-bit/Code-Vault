#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int amazing_score=1;
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(max<arr[i]){
            amazing_score++;
            max=arr[i];
        }
    }
    printf("amazing score: %d",amazing_score);
    return 0;
}