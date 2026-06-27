public class Power_Function {
    // Approach 1 
    public static double Power_Recursive(int x,int n){
        if(n==0){
            return 1;
        }
        if(n==1){
            return x;
        }
        if(x==0){
            return 0;
        }

        // Handle negative exponents: x^-n = 1 / x^n
        if (n < 0) {
            // We pass -n to make the exponent positive for the calculation,
            // then divide 1 by the result.
            return 1.0 / Power_Recursive(x, -n);
        }

        double Half_Power=Power_Recursive(x,n/2);

        if(n%2==0){
            // When Power is even
            return Half_Power*Half_Power;
        }
        else{
            // When Power is odd
            return x * Half_Power * Half_Power;
        }
    }

    // Approach 2
    public static double Power_Iterative(double x,int n){
        if(x==1 || n==0){
            return 1.0;
        }
        if(n==1){
            return x;
        }

        long N=n; // To prevent Overflow

        if(N<0){  // to handle Negative Powers
            x = 1.0 / x ;
            N = -N;
        }

        double ans = 1.0;
        double curr_product = x;

        while(N>0){
            // If the Power is odd at any time , we will multiply x with our ans
            if((N & 1) == 1){  // N % 2 == 1
                ans = ans * curr_product;
            }

            // Square the base for the next power of 2
            curr_product = curr_product * curr_product;

            N = N >> 1; // N /= 2
        }

        return ans;
    }
    public static void main(String[] args){
        int x=2;
        int n=10;

        System.out.println(Power_Iterative(x,n));
    }
}
