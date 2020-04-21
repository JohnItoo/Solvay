import java.io.*;
import java.util.*;


public class BandF {
    public static void main(String[] args) {

        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        String a = sc.nextLine();
        String[] s = a.split(" ");
        int n = Integer.parseInt(s[0]);
        int idx = Integer.parseInt(s[1]);
        String b = sc.nextLine();
        String[] d = b.split(" ");
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(d[i]);
        }
        int ans = 0;

        if (n == 1) {
            ans = arr[0] == 1 ? 1 : 0;

        } else {

            // 1 indexed

            int house = idx - 1;


            //border guys.
            if (house == n - 1) {
                int j = house;
                while (j >= 0) {
                    if (arr[j] == 1) {
                        ans++;
                    }
                    j++;
                }
            } else if (house == 0) {
                int j = house;
                while (j < n) {
                    if (arr[j] == 1) {
                        ans++;
                    }
                    j++;
                }
            } else {
                int j = house;
                int k = house;

                if (arr[k] == 1) {
                    ans++;
                }
                j--;
                k++;

                while (j >= 0 && k < n) {
                    if (arr[j] == 1 && arr[k] == 1) {
                        ans += 2;
                    }
                    j--;
                    k++;
                }

                if (j > 0) {
                    while (j >= 0) {
                        if (arr[j] == 1) {
                            ans++;
                        }
                        j--;
                    }
                } else if (k != n - 1) {
                    while (k < n) {
                        if (arr[k] == 1) {
                            ans++;
                        }
                        k++;
                    }
                }
            }
        }

        out.print(ans);

        //








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
