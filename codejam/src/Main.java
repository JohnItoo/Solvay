import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br;
    static StringTokenizer tokenizer;

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        int tc = nextInt();
        for(int i = 1; i <= tc; i++) {
            int N = nextInt();
            int[][] grid = new int[N][N];
            for(int row = 0; row<N; row++) {
                for(int col = 0; col<N; col++) {
                    grid[row][col] = nextInt();
                }
            }

            int total = 0; int rowMult = 0 ; int colMult = 0;
            HashMap<Integer, Integer> colMap = new HashMap<>();
            HashMap<Integer, Integer> rowMap = new HashMap<>();

            boolean row = false; boolean col = false;
            for(int idx = 0; idx < N; idx++) {
                total += grid[idx][idx];
                rowMap.clear(); colMap.clear();
                row = false; col = false;

                for(int trl = 0; trl < N; trl++) {
                    if(rowMap.containsKey(grid[idx][trl]) && !row) {
                        rowMult += 1;
                        row = true;
                    } else {
                        rowMap.put(grid[idx][trl], grid[idx][trl]);
                    }
                    if(colMap.containsKey(grid[trl][idx]) && !col) {
                        colMult += 1;
                        col = true;
                    } else {
                        colMap.put(grid[trl][idx], grid[trl][idx]);
                    }

                    if(col && row) break;
                }
            }
            System.out.println("Case #" + tc + ": " + total + " " + rowMult + " " + colMult);
        }
    }
    static String next() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null)
                throw new IOException();
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

     static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

     static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

}
