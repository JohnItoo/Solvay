import java.io.*;
import java.util.*;


public class MainOne {
    public static void main(String[] args) {

        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
         int n = sc.nextInt();

         while(n >0) {
             int a = 0;
             int b = 0;
             int d = 0;
             int ks  = 0;
             d = sc.nextInt();
             a = check(d) ;
             b = d - a;
             ks++;
             System.out.println("Case #"+ ks+": "+ a+ " "+ b);
         }


        out.close();
    }
    public static int check(int d) {
       String s = String.valueOf(d);
       StringBuilder sb = new StringBuilder();
       for(int i = 0; i<s.length(); i++) {
           if(s.charAt(i) == '4') {
              sb.append('1');
           } else {
               sb.append(s.charAt(i));
           }
       }
       return Integer.parseInt(sb.toString());
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
