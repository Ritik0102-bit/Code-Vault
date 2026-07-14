public class Quick_Sort {
    public static int Partition(int[] arr,int start,int end){
        int idx = start - 1;
        int pivotElem = arr[end];
        
        for(int j=start;j<end;j++){
            // Putting all the smaller elements on the left of pivot element
            if(arr[j] <= pivotElem){
                idx++;
                // swap the current element with the correct idx
                int temp = arr[idx];
                arr[idx] = arr[j];
                arr[j] = temp;
            }
        }
        
        // Now put the pivot element on its correct position 
        idx++;
        int temp = arr[idx];
        arr[idx] = arr[end];
        arr[end] = temp;

        return idx;
    }

    public static void Quick_Sort(int[] arr,int start,int end){
        if(start < end){
            int pivotIdx = Partition(arr,start,end);

            Quick_Sort(arr,start,pivotIdx-1);
            Quick_Sort(arr,pivotIdx+1,end);
        }
    }
    public static void main(String[] args){
        int[] arr = {5,4,3,1,2,6};

        Quick_Sort(arr, 0, arr.length-1);

        for(int i:arr){
            System.out.print(i + " ");
        }
    }
}
