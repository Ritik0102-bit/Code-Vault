public class Square_Root {
    public static int mySqrt(int x) {
        if (x == 0)
            return 0;

        int left = 1;
        int right = x;
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2; // Prevents overflow of left + right

            // Instead of mid * mid <= x, we use mid <= x / mid to prevent overflow
            if (mid <= x / mid) {
                result = mid; // mid could be the answer, but let's see if we can find a bigger one
                left = mid + 1;
            } else {
                right = mid - 1; // mid is too big
            }
        }

        return result;
    }


    public static long  mySqrt_2(int x) {
        // Handle edge cases for 0 and 1
        if (x < 2) return x;
        
        // Use long long to prevent integer overflow
        long i = 1; 
        
        while (i <= x / 2) {
            if (i * i == x) {
                return i;
            }
            if (i * i > x) {
                break;
            }
            i++;
        }
        return i - 1;
    }

    public static void main(String[] args) {
        System.out.println(mySqrt(9));
    }
};