package random;

public class ReplaceSpace {
    public static void main(String[] args) {
        System.out.println(replaceSpaces("lets go"));
    }

    public static String replaceSpaces(String s) {
        char[] charArray = s.toCharArray();
        int len = charArray.length;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < len; ++i) {
            if (charArray[i] == ' ') {
                sb.append("%");
            } else {
                sb.append(charArray[i]);
            }
        }
        return sb.toString();

    }

}
