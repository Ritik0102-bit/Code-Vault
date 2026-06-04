public class roman_to_number {
    
    // Helper method to get the integer value of a single Roman character
    private static int get_value(char ch) {
        switch (ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0; // Handles invalid characters safely
        }
    }

    public static int roman_to_int(String roman) {
        int total = 0;
        
        // Loop through each character in the string
        for (int i = 0; i < roman.length(); i++) {
            int current_value = get_value(roman.charAt(i));
            
            // Check if there is a next character AND if its value is greater than the current one
            if (i + 1 < roman.length() && get_value(roman.charAt(i + 1)) > current_value) {
                total -= current_value; // We subtract it (e.g., the 'I' in 'IV')
            } else {
                total += current_value; // Otherwise, we add it
            }
        }
        
        return total;
    }

    public static void main(String[] args) {
        String roman = "MCMLXXXVII"; // 1987. Change this string to test.

        int result = roman_to_int(roman);

        // Print the final integer result
        System.out.println(result);
    }
}