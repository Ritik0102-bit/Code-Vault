public class number_to_words {
    public static String number_to_word(int number){
        if (number == 0) {
            return "zero";
        }

        // Basic word dictionaries
        String[] units = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
                "nineteen" };
        String[] tens = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
        String[] scales = { "", "thousand", "million", "billion" };

        String result = "";
        int scaleIndex = 0; // Tracks if we are at thousands, millions, etc.

        // Loop through the number, processing 3 digits at a time
        while (number > 0) {
            int chunk = number % 1000; // Get the last 3 digits

            if (chunk > 0) {
                String chunkWords = "";

                int hundreds = chunk / 100;
                int remainder = chunk % 100; // The last two digits

                // 1. Handle Hundreds
                if (hundreds > 0) {
                    chunkWords += units[hundreds] + " hundred ";
                }

                // 2. Handle Tens and Units
                if (remainder > 0) {
                    if (remainder < 20) {
                        chunkWords += units[remainder] + " ";
                    } else {
                        chunkWords += tens[remainder / 10] + " ";
                        if (remainder % 10 > 0) {
                            chunkWords += units[remainder % 10] + " ";
                        }
                    }
                }

                // 3. Attach the scale (thousand, million) and add to the final result
                String scaleWord = scales[scaleIndex];
                if (!scaleWord.isEmpty()) {
                    scaleWord += " ";
                }

                // Prepend this chunk to the final result
                result = chunkWords + scaleWord + result;
            }

            number = number / 1000; // Chop off the last 3 digits and repeat
            scaleIndex++; // Move to the next scale (e.g., from ones to thousands)
        }

        return result;
    }
    public static void main(String[] args) {
        int number = 1234567; // Change this number to test

        String result=number_to_word(number);

        // Print the result, trimming any extra spaces off the ends
        System.out.println(result.trim());
    }
}
