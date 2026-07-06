// if any row or column that contains at least one zero. 
// then modify the matrix by replacing every element in these rows or column

#include<stdio.h>
void modifymatrix(int r,int c,int arr[r][c]){
    int rowflags[r],colflags[c];
    for(int i=0;i<r;i++){
        rowflags[i]=0;
    }
    for(int i=0;i<c;i++){
        colflags[i]=0;
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]==0){
                rowflags[i]=1;
                colflags[j]=1;
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(rowflags[i]==1 || colflags[j]==1){
                arr[i][j]=0;
            }
        }
    }
}
int main(){
    int r,c;
    scanf("%d%d",&r,&c);
    int arr[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    modifymatrix(r,c,arr);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}