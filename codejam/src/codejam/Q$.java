package codejam;

import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Q${
    static BufferedReader br;
    static StringTokenizer tokenizer;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        int T = nextInt();
        for (int tc = 1; tc <= T; tc++) {
            int n,b , f = 0;
            String s = next();
            String[] st = s.split(" ");
             n = Integer.parseInt(st[0]) ; b =Integer.parseInt(st[1]);  f =Integer.parseInt(st[2]);
             StringBuilder sb;
             String[] ans = new String[f+1];
           int idx = 1;
           while(idx <= f) {
               sb = new StringBuilder();
               for(int i = 1 ; i<=n; i++) {
                   if(idx == i) {
                       sb.append("0");
                   } else {
                       sb.append("1");
                   }
               }
               System.out.println(sb.toString());
               System.out.flush();
               ans[idx] = next();
               idx++;
           }
           ArrayList<Integer> brkn = new ArrayList<>();
           for(int i = 1; i<ans.length; i++) {
               String gee = ans[i];
               boolean wrks = false;
               for(int j = 0; j <gee.length(); j++) {
                   if(gee.charAt(j) == '0') {
                     wrks = true;
                     break;
                   }
               }
               if(!wrks) {
                   brkn.add(i);
               }
           }

           for(int a : brkn) {
               System.out.print(a +" ");
           }
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