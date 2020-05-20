import java.io.*;
import java.util.*;
 
 
public class Main {
    public static void main(String[] args) {
 
        MyScanner in = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int tc = in.nextInt();
        Task solver = new Task();
        for(int i = 1; i<=tc; i++) {
          solver.solve(i, in, out);
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


    public static class Task {
      public void solve(int i, MyScanner in, PrintWriter out) {

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