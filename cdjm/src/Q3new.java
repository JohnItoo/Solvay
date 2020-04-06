
import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Q3new{
    static BufferedReader br;
    static StringTokenizer tokenizer;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        int T = nextInt();
        for (int tc = 1; tc <= T; tc++) {
            int L;
            next();
            L = nextInt();
            ArrayList<BigInteger> gb = new ArrayList<>();
            for (int i = 0; i < L; i++) {
                gb.add(new BigInteger(next()));
            }
            ArrayList<BigInteger> primeList = new ArrayList<>();
            ArrayList<BigInteger> noReps = new ArrayList<>();
            BigInteger gcd = gb.get(0).gcd(gb.get(1));
            primeList.add(gb.get(0).divide(gcd));
            primeList.add(gcd);
            primeList.add(gb.get(1).divide(gcd));
            for (int i = 2; i < L; i++) {
                primeList.add(gb.get(i).divide(primeList.get(i)));
            }

            for (int i = 0; i <= L; i++) {
                if (!noReps.contains(primeList.get(i))) {
                    noReps.add(primeList.get(i));
                }
            }
            Collections.sort(noReps);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i <= L; i++) {
                int x = noReps.indexOf(primeList.get(i));
                x = x + 'A';
                char c = (char) x;
               sb.append(c);
            }
            System.out.println("Case #" + tc + ": " + sb.toString());
        }
    }

    public static String next() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null)
                throw new IOException();
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    public static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }


}