public class Substrings_of_Strings {
    public static void printAllSubstrings(String str) {
        int n = str.length();
        
        // The outer loop picks the starting point (inclusive)
        for (int start = 0; start < n; start++) {
            
            // The inner loop picks the ending point (exclusive)
            for (int end = start + 1; end <= n; end++) {
                
                // Extract and print the substring
                System.out.println(str.substring(start, end));
            }
        }
    }

    public static void main(String[] args) {
        String text = "cat";
        
        System.out.println("All substrings of '" + text + "':");
        System.out.println("----------------------");
        printAllSubstrings(text);
    }
}