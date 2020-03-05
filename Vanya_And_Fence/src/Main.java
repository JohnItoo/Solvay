import java.io.*;
import java.util.*;


public class Main {
    public static void main(String[] args) {

        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n = sc.nextInt();
        int h = sc.nextInt();
        String input = sc.nextLine();
        int nb = 0;

        String[] split = input.split(" ");
        for (int i = 0 ; i < n; i++) {
            int a = Integer.parseInt(split[i]);
            if (a > h) {
                nb++;
            }
        }
        int solution = (n - nb) + (nb * 2);
        out.print(solution);
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

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }
}
