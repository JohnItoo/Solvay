
import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Q3c{
    static BufferedReader br;
    static StringTokenizer tokenizer;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        int T = nextInt();
        for (int test = 1; test <= T; test++) {
            System.out.print("Case #" + test + ": ");
            int L; next(); L = nextInt();
            ArrayList<BigInteger> data = new ArrayList<>();
            for (int i = 0; i < L; i++) {
                data.add(new BigInteger(next()));
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
            System.out.println();
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