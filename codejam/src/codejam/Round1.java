package codejam;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Round1 {
    static BufferedReader br;
    static StringTokenizer tokenizer;

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        int tc = nextInt();
        for(int i = 1; i <= tc; i++) {
          int no = nextInt();
          String [] arr = new String [no];
            boolean [] pckd = new boolean[no];
           while(no >= 1) {
               arr[no-1]  = next();
               no --;
            }

            int ans = 0;
           int max = 0;
            ArrayList<String> ar = new ArrayList<>();
            for(int j =0 ; j<arr.length -1; j++) {
               for(int r = j + 1; r < arr.length; r++) {
                   int dg = arr[r].length();
                   int da = arr[j].length();
                   boolean ent = false, isact = false;

                   while (dg > 0 && da > 0) {
                       if (arr[r].substring(dg-1).equals(arr[j].substring(da-1)) && (!pckd[r] && !pckd[j])) {
                           ans++;
                           isact = true;
                           ent = true;
                           }

                       if(isact && !(arr[r] .substring(dg-1).equals(arr[j].substring(da-1)))) {
                           pckd[r] = true;
                           pckd[j] = true;
                           ar.add(arr[r].substring(dg));
                           break;
                       }

                       dg --;
                       da--;
                   }


                   max = Math.max(ans, max);
                   if(ent) break;

               }
            }

            int div = 0;
            Collections.sort(ar);

            for(int pr = 0; pr < ar.size() - 1; pr++) {
                String one = ar.get(pr);
                String two = ar.get(pr +1);

                if(one.equals(two)) {
                    div++;
                }
            }
               if(div > 1) {
                System.out.println("Case #" + i + ": " +max/div+ " ") ;
               } else {
                   System.out.println("Case #" + i + ": " +max+ " ") ;

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
