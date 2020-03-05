
    import java.util.*;
import java.io.*;

    public class Q2 {
        static BufferedReader br;
        static StringTokenizer tokenizer;

        public static void main(String[] args) throws Exception {
            br = new BufferedReader(new InputStreamReader(System.in));
            int tc = nextInt();
            for(int i = 1; i <= tc; i++) {
                nextInt();
                String str = next();
                char[] arr = new char[str.length()];
                for(int k = 0; k < str.length(); k++) {
                    if(str.charAt(k) == 'S')
                        arr[k] = 'E';
                    else
                        arr[k] = 'S';
                }
                String s = new String(arr);
                System.out.println("Case #" + i + ": " + s);
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
