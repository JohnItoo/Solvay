
import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Qanswer {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T = in.nextInt();
        for (int test = 1; test <= T; test++) {
            System.out.print("Case #" + test + ": ");
            int L;
            in.next();
            L = in.nextInt();
            ArrayList<BigInteger> data = new ArrayList<>();
            for (int i = 0; i < L; i++) {
                data.add(new BigInteger(in.next()));
            }
            ArrayList<BigInteger> primeList = new ArrayList<>();
            ArrayList<BigInteger> noReps = new ArrayList<>();
            BigInteger gcd = data.get(0).gcd(data.get(1));
            primeList.add(data.get(0).divide(gcd));
            primeList.add(gcd);
            primeList.add(data.get(1).divide(gcd));
            for (int i = 2; i < L; i++) {
                primeList.add(data.get(i).divide(primeList.get(i)));
            }

            for (int i = 0; i <= L; i++) {
                if (!noReps.contains(primeList.get(i))) {
                    noReps.add(primeList.get(i));
                }
            }
            Collections.sort(noReps);
            for (int i = 0; i <= L; i++) {
                int x = noReps.indexOf(primeList.get(i));
                x = x + 'A';
                char c = (char) x;
                System.out.print(c);
            }
        }
            System.out.println();
        }



}