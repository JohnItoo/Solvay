package leetcode;

public class PalindromePartitioningII {
    //THis is for twoHalves

    public static int minCut(String s) {
        int solution = 1;
        int j = 1;

        if (s.length() == 1) {
            return 0;
        }

        if (s.length() == 2) {
            if (s.charAt(0) == s.charAt(1)) {
                return 1;
            } else {
                return 0;
            }
        }

        while (j < s.length() - 1) {
            String substringHead = s.substring(0, j);
            String substringTail = s.substring(j, s.length());
            if (isSubStringPalindrome(substringHead) &&
                    isSubStringPalindrome(substringTail)) {
                return solution;
            }
            j++;
            solution++;
        }
        return solution;


    }

    private static boolean isSubStringPalindrome(String substring) {
        int begin = 0;
        int end = substring.length() - 1;

        while (end > begin) {
            if (substring.charAt(begin) != substring.charAt(end)) {
                return false;
            }
            end--;
            begin++;
        }
        return true;
    }

}
