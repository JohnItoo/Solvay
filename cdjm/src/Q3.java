
import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Q3 {
    static BufferedReader br;
    static StringTokenizer tokenizer;

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        int tc = nextInt();
        for(int i = 1; i <= tc; i++) {

            nextInt();
            int L = nextInt();
            ArrayList<BigInteger> bg = new ArrayList<>();
            for (int j = 0; j < L; j++) {
                int nI = nextInt();
                bg.add(BigInteger.valueOf(nI));
            }
            ArrayList<BigInteger> primes = new ArrayList<>();
            ArrayList<BigInteger> rep = new ArrayList<>();
            BigInteger gcd = bg.get(0).gcd(bg.get(1));
            primes.add(bg.get(0).divide(gcd));
            primes.add(gcd);
            primes.add(bg.get(1).divide(gcd));
            for (int k = 2; k < L; k++) {
                BigInteger nx = bg.get(i).divide(primes.get(i));
                primes.add(nx);
            }

            for (int m = 0; m <= L; m++) {
                if (!rep.contains(primes.get(i))) {
                    rep.add(primes.get(i));
                }
            }
            Collections.sort(rep);
            StringBuilder sb = new StringBuilder();
            for (int q = 0; q <= L; q++) {
                int x = rep.indexOf(primes.get(i));
                x = x + 'A';
                char c = (char) x;
                sb.append(c);

            }
            System.out.println("Case #" + i + ": " + sb.toString());

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
