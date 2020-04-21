import java.io.*;
import java.util.*;


public class FakeMain {
    public static void main(String[] args) {

        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int n = sc.nextInt();

        int[] candies = new int[n+1];
        ArrayList<Integer> temp = new ArrayList<>();
        String s = sc.nextLine();
        String[] sol = s.split(" ");
        int even;
        int odd;
        int ans = 0;
        int it = 0;


        for (int i = 1; i <= n ; ++i ) {
            candies[i] = Integer.parseInt(sol[i -1]);
        }

        for (int i = 1; i<=n ; ++i) {
            even = 0;
            odd = 0;
            it = 0;

            for (int w = 1; w <= n ; ++w) {

                if(i != w) {
                   it++;
                   if (it % 2 == 0) {
                       even +=  candies[w];
                   } else {
                       odd += candies[w];
                   }
                }
            }
            if (odd == even) {
                ans++;
            }

            }
        out.print(ans);


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
