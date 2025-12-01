public class A {
    public static int[] productExceptSelf(int[] nums) {
         int[] answer = new int[nums.length];
        int ans=1;
        boolean zero=false;
        for(int i:nums){
            if(i!=0){
                ans*=i;
            }
            else{
                zero=true;
            }
        }
        System.out.println( ans);
        for(int i=0;i<nums.length;i++){
            if(zero==true && nums[i]!=0){
                answer[i]=0;
            }
            else if(zero==true && nums[i]==0){
                answer[i]=ans;
            }
            else{
                double div=Math.pow(nums[i],-1);
                System.out.println(div);
                answer[i]=(int)(ans*div);
            }
            
        }
        return answer;
    }

    public static void main(String[] args) {
        int[] arr = { -1,1,0,-3,3};

        int[] res = productExceptSelf(arr);

        for (int i : res) {
            System.out.print(i + " ");
        }
    }
}
