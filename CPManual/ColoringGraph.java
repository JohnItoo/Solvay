package CPManual;

import java.io.*;
import java.util.*;

class Main {
    private static PrintWriter out;
    private static int result;
    private static ArrayList<Integer> way;
    private static ArrayList<Integer>[] graph;
    private static int edeges;
    private static boolean[] bools;

     public static void main(String[] args) {

        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int TC = sc.nextInt();

        while (TC > 0) {
            int N = sc.nextInt();
            int E = sc.nextInt();
            result = 0;
            edeges = N;
            graph = new ArrayList[N + 1];
            way = new ArrayList<>();
            bools = new boolean[N + 1];
            for (int i = 0; i <= N; ++i) {
                graph[i] = new ArrayList<>();
            }
            while (E > 0) {
                int a = sc.nextInt();
                int b = sc.nextInt();
                graph[a].add(b);
                graph[b].add(a);
                E--;
            }
            color(1, 0);
            System.out.println(way.size());
            for(int a = 0; a < way.size(); a++) {

                if(a != 0) {
                    System.out.print(" " + way.get(a));
                } else {
                    System.out.print(way.get(a));
                }
            }
            System.out.println();
            TC--;
        }
        out.close();
    }

    private static boolean canColorBlack(int node) {
        for (int a : graph[node]) {
            if (bools[a]) {
                return false;
            }
        }
        return true;
    }

    private static void color(int node, int blacks) {
        if (node < edeges) {
            if (canColorBlack(node)) {
                bools[node] = true;
                color(node + 1, blacks + 1);
                bools[node] = false;
            }
            color(node + 1, blacks);
            return;
        }
        if (blacks > result) {
            result = blacks;
            way.clear();
            for (int i = 0; i < bools.length; ++i) {
                if (bools[i]) {
                    way.add(i);
                }
            }
        }
    }

     static class MyScanner {
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
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

    }
}