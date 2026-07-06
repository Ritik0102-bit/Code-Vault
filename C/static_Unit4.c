// You are using GCC
#include<stdio.h>
int countOccurrenceofdigitInteger(int num,int digit)
{
    int count=0;
    while(num>0)
    {
        if(num%10==digit)
        {
            count++;
        }
        num=num/10;
    }
    return count;
}
 int countOccurrenceInArray(int arr[],int size,int digit)
{   int totalCount=0;
       for(int i=0;i<size;i++)
       {
           totalCount=totalCount+countOccurrenceofdigitInteger(arr[i],digit);
       }
       return totalCount;
}

int main()
{
    int a[15],size,digit;
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&digit);
    printf("%d times",countOccurrenceInArray(a,size,digit));
    
}













#include<stdio.h>
int main()
{
   float a[10];
   int size,count=0;
   scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        scanf("%f",&a[i]);
        if(a[i]>3.5)
        {
            count++;
        }
        
    }
    
    if(count==0)
    {
        printf("No students found with GPA > 3.5");
    }
    else
    printf("%d",count);
    
}














#include <stdio.h>
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) 
    {
        int mid = (low + high) / 2;
              if (arr[mid] == target)
            return mid;
              if (arr[mid] < target)
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return -1; 
}

int main() {
    int N, target;
       scanf("%d", &N);
    int arr[N];
       for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
       scanf("%d", &target);
       int result = binarySearch(arr, 0, N - 1, target);
       if (result != -1)
        printf("The target value %d is present at index %d\n", target, result);
    else
        printf("The target value %d is not present in the array\n", target);
    
    return 0;
}


















#include <stdio.h>
int sumOfDigits(int num) 
{
    int sum = 0;
    while (num > 0) 
    {
        sum =sum+ num % 10;
        num=num/10;
    }
    return sum;
}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sumOfDigits(arr[j]) > sumOfDigits(arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int studentIDs[N];
     for (int i = 0; i < N; i++) {
        scanf("%d", &studentIDs[i]);
    }
     bubbleSort(studentIDs, N);
       for (int i = 0; i < N; i++) {
        printf("%d ", studentIDs[i]);
    }
    printf("\n");
  return 0;
}










// sorting of a paticular column of a matrix

#include <stdio.h>

void bubbleSortColumn(int arr[][10], int rows, int cols, int colIndex) {
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < rows - i - 1; j++) {
            if (arr[j][colIndex] > arr[j + 1][colIndex]) {
                
                    int temp = arr[j][colIndex];
                    arr[j][colIndex] = arr[j + 1][colIndex];
                    arr[j + 1][colIndex] = temp;
                }
            }
        }
    
}

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    int arr[10][10];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int colIndex;
    scanf("%d", &colIndex);

    bubbleSortColumn(arr, rows, cols, colIndex);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}