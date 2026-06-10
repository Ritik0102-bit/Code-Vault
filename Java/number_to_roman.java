public class number_to_roman {

    public static String int_to_roman(int number) {
        // Roman numerals are typically defined only for numbers between 1 and 3999
        if (number <= 0 || number > 3999) {
            return "Number must be between 1 and 3999";
        }

        // Parallel arrays for values and their Roman symbols, ordered from largest to
        // smallest
        int[] values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        String result = "";

        // Loop through the values
        for (int i = 0; i < values.length; i++) {
            // While the number is greater than or equal to the current value
            while (number >= values[i]) {
                result += symbols[i]; // Append the Roman symbol
                number -= values[i]; // Subtract the value from the number
            }
        }

        return result;
    }

    public static void main(String[] args) {
        int number = 1987; // Change this number to test

        String result = int_to_roman(number);

        // Print the final Roman numeral string
        System.out.println(result);
    }
}