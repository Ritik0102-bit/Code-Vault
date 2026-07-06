#include<stdio.h>
int main(){
    char arr[7];
    int i;
    for( i=0;i<7;i++){
        scanf("%c",&arr[i]);
    }
    char arr1[5]={'a','e','i','o','u'};
    int count=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(arr[i]==arr1[j]){
                count+=1;
            }
        }
    }
    printf("count of vowels in the list: %d",count);
}