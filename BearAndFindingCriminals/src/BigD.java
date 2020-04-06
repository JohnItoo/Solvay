import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class BigD {
    public static void main(String[] args) {

        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int n = sc.nextInt();

        int count = 0;
        BigDecimal[] ans = new BigDecimal[n];

        while (count < n) {
            String s = sc.nextLine();
            String[] id = s.split(" ");
            BigDecimal l = new BigDecimal(id[0]);
            BigDecimal a =  new BigDecimal(id[1]);
            BigDecimal b =  new BigDecimal(id[2]);

            if (!l.divide(new BigDecimal(2)).equals(0)) {
                 if(((l .divide( new BigDecimal(2))).multiply(b)).compareTo(l.multiply(a)) > 0) {
                     ans[count] = l.multiply(a);
                 } else {

                     ans[count] = ((l .divide( new BigDecimal(2))).multiply(b));
                 }

            } else {
                BigDecimal sol = ((((l.subtract(new BigDecimal(1))).divide(new BigDecimal(2))).multiply(b))).add(a);

                if(sol.compareTo(l.multiply(a)) > 0) {
                    ans[count] = l.multiply(a);
                } else {
                    ans[count] = sol;
                }
            }

            count++;
        }

        for (int i = 0; i < n; i++) {
            out.println(ans[i]);
        }


        // Start writing your solution here. -------------------------------------

      /*
      int n      = sc.nextInt();        // read input as integer
      long k     = sc.nextLong();       // read input as long
      double d   = sc.nextDouble();     // read input as double
      String str = sc.next();           // read input as String
      String s   = sc.nextLine();       // read whole line as String

      int result = 3*n;
      out.println(result);                    // print via PrintWriter
      */

        // Stop writing your solution here. -------------------------------------
        out.close();
    }

    public static PrintWriter out;

    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
        //--------------------------------------------------------

    }
}
