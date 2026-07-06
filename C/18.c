#include<stdio.h>
int main(){
    int arr[100];
    int position,i,n,value;
    printf("Enter number of elements in array:\n");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for( i=0;i<n;i++){
        scanf("%c",&arr[i]);
    }
    printf("Enter the location where you want to insert an element:\n");
    scanf("%d",&position);
    printf("Enter the value:\n");
    scanf("%d",&value);
    for(i=n-1;i>=position;i--){
        arr[i+1]=arr[i];
    }
    arr[position]=value;
    printf("Resultant array is:\n");
    for(i=0;i<=n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}