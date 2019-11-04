
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

 public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        OutputStream outputStream = System.out;
        PrintWriter out = new PrintWriter(outputStream);
        Superhero solution = new Superhero();
        solution.solution(sc,out);
        out.close();
    }
}

class Superhero {
  //  String vowels = "aeiou"; could have used this and looped through/
   public  void solution(Scanner in, PrintWriter out) {
        String s = in.next();
        String t = in.next();
        boolean canTrans = true;


        if (s.length() != t.length()) {
            out.print("No");
            return;
        }
        for (int i = 0; i<s.length(); i++) {

           if ((isVowel(s.charAt(i)) && isVowel(t.charAt(i)))
                               || (!isVowel(s.charAt(i)) && !isVowel(t.charAt(i)))) {
              continue;

           }
           canTrans = false;
           break;

        }
        if (canTrans) {
            out.print("Yes");
        } else {
            out.print("No");
        }

    }

   public boolean isVowel(char c) {
       return ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'));
    }
}

