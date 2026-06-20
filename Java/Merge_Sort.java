// Time Complexity : O(nlogn)

// Based On Divide & Conquer Approach

public class Merge_Sort {

    public static void Conquer(int[] arr,int start,int mid,int end){
        int[] merged = new int[end - start + 1];
        int idx = 0;
        int idx_1 = start;
        int idx_2 = mid + 1;

        while(idx_1 <= mid && idx_2 <= end){
            if(arr[idx_1] <= arr[idx_2]){
                merged[idx++] = arr[idx_1++];
            }
            else{
                merged[idx++] = arr[idx_2++];
            }
        }

        while(idx_1 <= mid){
            merged[idx++] = arr[idx_1++];
        }

        while (idx_2 <= end) {
            merged[idx++] = arr[idx_2++];
        }

        for(int i=0 , j=start ; i<merged.length ; i++ , j++){
            arr[j] = merged[i];
        }
    }

    public static void Divide(int[] arr,int start,int end){
        if(start >= end){
            return;
        }

        int mid = start + (end - start)/2;
        Divide(arr,start,mid);
        Divide(arr,mid+1,end);
        Conquer(arr,start,mid,end);
    }

    public static void main(String[] args){
        int arr[] = {1,4,2,1,2,1,3,9};

        Divide(arr,0,arr.length-1);

        for(int i:arr){
            System.out.print(i + " ");
        }
    } 
}
