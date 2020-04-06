import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class WaterBuying {

    public static void main(String[] args) {


        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int n = sc.nextInt();

        int count = 0;
        BigInteger[] ans = new BigInteger[n];

        while (count < n) {
            String s = sc.nextLine();
            String[] id = s.split(" ");
            BigInteger l = new BigInteger(id[0]);
            BigInteger a =  new BigInteger(id[1]);
            BigInteger b =  new BigInteger(id[2]);
            BigInteger two = new BigInteger("2");
            BigInteger result;

              BigInteger mult = b.min((a.multiply(two)));
               BigInteger sol1 = ((l.divide(two)).multiply(mult)).add((l.mod(two)).multiply(a));
               ans[count]= sol1;
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
