package ladders;

import java.io.*;
import java.util.StringTokenizer;


public class CF78D2B { //class name is Main and we would remove package header.
    public static void main(String[] args) {

        MyScanner in = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        Task solver = new Task();
        solver.solve(1, in, out);




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


    public static class Task {
        public void solve(int tc, MyScanner in, PrintWriter out) {
            String rn = "ROYGBIV";
            String[] sa = {"", "G", "GB", "YGB", "YGBI", "OYGBI", "OYGBIV"};
            int t = in.nextInt();
            StringBuilder sb = new StringBuilder();
            int fr = t/7;
            for(int i = 0; i<fr; i++) {
                sb.append(rn);
            }
            sb.append(sa[t%7]);
            out.println(sb.toString());
        }
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