import java.io.*;
import java.util.*;


public class Main {
    public static void main(String[] args) {

        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        String first = sc.nextLine();
        String[] guys = first.split(" ");
        int cit = Integer.parseInt(guys[0]);
        int idx = Integer.parseInt(guys[1]);
        int[] crim = new int[cit];
        String second = sc.nextLine();
        String[] gus = second.split(" ");

        for(int i = 0; i<gus.length; i++) {
            crim[i] = Integer.parseInt(gus[i]);
        }

       int[] sol = new int[cit];
        int rem = cit - (2 * idx);
        int add = 0;

        for (int d = 0; d<cit; d++) {
//            int x = Math.abs(idx-1-i);
//            sol[x] += crim[x];
//            if(crim[i] == 1 && i > idx * 2) {
//                add++;
//            }

            int front = idx - 1 + d;
            int back = idx - 1 - d;
            if (front >= 0 && front < cit && back >= 0 && back < cit) {
                if((crim[front] == 1 && crim[back] == 0) || (crim[front] == 0 && crim[back] == 1)) {
                    add++;
                }
            }
        }
//        int ans = 0;
//        for (int i = 0; i< cit; i++) {
//            if(sol[i] <= 2 && sol[i] >0){
//               ans++;
//
//            }
//        }
        out.println( add);



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
