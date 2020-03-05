package random;

class LongestCommonPrefix {
    String prefix = "";

    public String longestCommonPrefix(String[] strs) {
        if (strs.length > 1) {
            prefix = checkCharArray(strs[0], strs[1]);
            for (int i = 2; i < strs.length; i++) {
                if (prefix.isEmpty()) {
                    return "";
                } else {
                    prefix = checkCharArray(prefix, strs[i]);
                    System.out.println(prefix);
                }
            }
        } else if (strs.length == 1) {
            prefix = strs[0];
        }
        return prefix;
    }


    private String checkCharArray(String string1, String string2) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < getLengthOfShorterStringSet(string1, string2); i++) {
            if (string1.charAt(i) == string2.charAt(i)) {
                sb.append(string1.charAt(i));
                System.out.println("SB : " + sb);
            } else {
                return sb.toString();

            }
        }
        return sb.toString();
    }

    private int getLengthOfShorterStringSet(String string1, String string2) {
        if (string1.length() < string2.length()) {
            return string1.length();
        } else {
            return string2.length();
        }
    }
}
