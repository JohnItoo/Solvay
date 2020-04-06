
import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Q3Mod{
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
            BigInteger[] primeList = new BigInteger[L+1];
            ArrayList<BigInteger> noReps = new ArrayList<>();
            int pivot = 0;
            BigInteger gcd;

            for (int i = 0; i < L-2; i++) {
                if(!gb.get(i).equals( gb.get(i+1))) {
                    pivot = i;
                    gcd = gb.get(i).gcd(gb.get(i+1));
                    primeList[i] = gb.get(i).divide(gcd);
                    primeList[i+1] = gcd;
                    primeList[i+2] = gb.get(i+1).divide(gcd);
                }
            }

            for (int i = pivot - 1; i >=0; i--) {
               primeList[i] = gb.get(i).divide(primeList[i+1]);
            }

            for (int i = pivot + 3; i <=L; i++) {
                primeList[i] = gb.get(i-1).divide(primeList[i-1]);
            }

            for (int i = 0; i <= L; i++) {
                if (!noReps.contains(primeList[i])) {
                    noReps.add(primeList[i]);
                }
            }
            Collections.sort(noReps);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i <= L; i++) {
                int x = noReps.indexOf(primeList[i]);
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