class Plus_One {
    // Approach 1 : Carry Approach
    public static int[] plus_One(int[] digits) {
        int n = digits.length;

        int carry = 1;

        for (int i = n - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;

            // if carry is 0 , anytime
            if (carry == 0) {
                return digits;
            }
        }

        int[] result = new int[n + 1];
        result[0] = carry;
        return result;
    }

    // Approach 2 :
    // The problem asks us to add 1 to a number represented by an array. There are
    // three main scenarios we need to handle:

    // 1. No Carry at the End: The last digit is less than 9 (e.g., [1, 2, 3]
    // becomes [1, 2, 4]).

    // 2. Trailing Nines: The last digit(s) are 9, which means we need to carry the
    // 1 over (e.g., [1, 2, 9] becomes [1, 3, 0]).

    // 3. All Nines: The entire array is 9s, meaning we need to expand the array
    // size to hold an extra digit (e.g., [9, 9, 9] becomes [1, 0, 0, 0]).

    public static int[] plusOne(int[] digits) {
        int n = digits.length;

        // Start from the end of the array (least significant digit)
        for (int i = n - 1; i >= 0; i--) {
            // If the digit is less than 9, just add 1 and return the array
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // If the digit is 9, it becomes 0 (and the loop continues to carry the 1)
            digits[i] = 0;
        }

        // If the loop finishes without returning, it means all digits were 9.
        // We create a new array with one extra slot.
        // In Java, a new int array is automatically initialized with 0s.
        int[] newNumber = new int[n + 1];
        newNumber[0] = 1; // Just set the first digit to 1 (e.g., 99 -> 100)

        return newNumber;
    }

    public static void main(String[] args) {
        int[] digits = { 1, 2, 3 };

        // Use .clone() to pass a copy, keeping the original intact
        int[] res1 = plus_One(digits.clone());
        int[] res2 = plusOne(digits.clone());

        for (int i : res1) {
            System.out.print(i);
        }

        System.out.println();

        for (int i : res2) {
            System.out.print(i);
        }
    }
}
