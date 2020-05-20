package codejam;

import java.io.*;
import java.util.*;

public class Q1 {

        static BufferedReader br;
        static StringTokenizer tokenizer;

        public static void main(String[] args) throws Exception {
            br = new BufferedReader(new InputStreamReader(System.in));
            int tc = nextInt();
            for(int i = 1; i <= tc; i++) {
                char[] str = next().toCharArray();
                long a = 0;
                long b = 0;
                for(int k = 0; k < str.length; k++) {
                    if(str[k] == '4') {
                        a *= 10;
                        a += 2;
                        b *= 10;
                        b += 2;
                    }
                    else {
                        a *= 10;
                        a += Character.getNumericValue(str[k]);
                        b *= 10;
                    }
                }
                System.out.println("Case #" + i + ": " + a + " " + b);
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

