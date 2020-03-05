package random;

import java.util.Stack;

public class LongestPalindromicSubString {


    /*
    Two stacks temporary  and permanent. ba b ad
     */


    public static String longestPalindrome(String s) {

        Stack<Character> permanentStack = new Stack<>();
        Stack<Character> tempStack = new Stack<>();
        int max= 0;
        String palindrome = "";
        String tempPalindrome= "";
//        tempPalindrome.charAt()

        for (int i = 0; i < s.length(); i++) {
            permanentStack.push(s.charAt(i));
            tempStack.push(s.charAt(i));
            tempPalindrome = getPalindromeHere(tempStack, s.substring(i));
            if ( tempPalindrome.length() >= palindrome.length()) {
                palindrome = tempPalindrome;
            }

            tempStack = permanentStack;

        }
        return palindrome;
    }

    private static String getPalindromeHere(Stack<Character> tempStack,  String subString) {
        int i = 0;
        StringBuilder sbTemp = new StringBuilder();
        StringBuilder sbResult = new StringBuilder();
        while (tempStack.size() > 0 && i <= subString.length() - 1) {
               Character C = tempStack.pop();
            if (C == Character.valueOf(subString.charAt(i))) {
                sbTemp.append(C);
                sbTemp.append(sbResult);
                sbResult = sbTemp;
                sbTemp = new StringBuilder();
                i++;
            } else {
                return sbResult.toString();
            }

        }
        return sbResult.toString();
    }
}
