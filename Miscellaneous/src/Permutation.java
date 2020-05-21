import java.util.ArrayList;
import java.util.List;

public class Permutation {
    public static void main(String[] args) {
        permute("abc");
    }

    static List<String> sol = new ArrayList();
    private static void permute(String asda) {
       sol = permute(asda, asda.length() - 1);
       for(String ans : sol) {
           System.out.println(ans);
       }
    }

    /**
     * Description: What this does is it recursively builds the solution
     * the permutations of String of length n is the permutations of S(n-1) with String[n] at every index
     * e.g ab =  permutation of S[0] =  [a] with b at zero index = [ba] and b at first index [ab]
     * @param asda
     * @param span
     * @return
     */
    private static List<String> permute(String asda, int span) {
        if(span == 0) {
           List<String> curr = new ArrayList();
           curr.add(String.valueOf(asda.charAt(0)));
           return curr;
        }
        List<String> vals = permute(asda, span -1);
        List<String> nList = new ArrayList();

        for(String val : vals) {
            for(int i = 0; i <= span; ++i) {
                char[] arr = new char[span+1];
                int j = 0;
                int k = 0;
                while (k <= span) {
                    if (k == i) {
                        arr[k] = asda.charAt(span);
//                        System.out.println("asda at char is" + arr[k]);
                        k++;
                        continue;
                    }
                    arr[k] = val.charAt(j);
                    j++;
                    k++;
                }
                nList.add(new String(arr));
            }
        }
        return nList;
    }
}
