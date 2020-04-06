
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.Math;

public class Indicium {

    static BufferedReader br;
    static StringTokenizer tokenizer;
    static int targ = 0;

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        int tc = nextInt();
        for (int i = 1; i <= tc; i++) {
            System.out.print("Case #" + i + ": ");
            solve();
        }
    }


    static void solve() throws Exception {
        int N = nextInt();
        targ = nextInt();
        int[][] grid = new int[N][N];
        if(build(grid)) {
            System.out.print("POSSIBLE");
            System.out.println();
            print(grid, N);
        } else {
            System.out.print("IMPOSSIBLE");
        }
    }
    public static void print(int[][] board, int N)
    {
        // we got the answer, just print it
        for (int r = 0; r < N; r++)
        {
            for (int d = 0; d < N; d++)
            {
                System.out.print(board[r][d]);
                System.out.print(" ");
            }
            System.out.print("\n");

            if ((r + 1) % (int) Math.sqrt(N) == 0)
            {
                System.out.print("");
            }
        }
    }

  static boolean diagonal(int[][] grid) {
        int total = 0;
        for(int i = 0; i<grid.length; ++i) {
            total += grid[i][i];
        }
        System.out.println(total + " total : targ" + targ);
        return total == targ;
  }

    static boolean build(int[][] grid) {
        int row = -1;
        int col = -1;
        boolean isEmpty = true;
        int n = grid.length;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    row = i;
                    col = j;

                    isEmpty = false;
                    break;
                }
            }
            if (!isEmpty)
            {
                break;
            }
        }

        if (isEmpty)
        {
            return true;
        }

        // else for each-row backtrack
        for (int num = 1; num <= n; num++)
        {
            if (isSafe(grid, row, col, num))
            {
                grid[row][col] = num;
                if (build(grid)) {
                    if((row == n-1 && col == n-1) && !diagonal(grid)) {
                        System.out.println("return false");
                        return false;
                    }
                    return true;
                }
                else
                {
                    grid[row][col] = 0; // replace it
                }
            }
        }
        return false;
    }

    public static boolean isSafe(int[][] board,
                                 int row, int col,
                                 int num)
    {
        // row has the unique (row-clash)
        for (int d = 0; d < board.length; d++)
        {
            // if the number we are trying to
            // place is already present in
            // that row, return false;
            if (board[row][d] == num)
            {
                return false;
            }
        }

        // column has the unique numbers (column-clash)
        for (int r = 0; r < board.length; r++)
        {
            // if the number we are trying to
            // place is already present in
            // that column, return false;

            if (board[r][col] == num)
            {
                return false;
            }
        }

//        // corresponding square has
//        // unique number (box-clash)
        int sqrt = (int) Math.sqrt(board.length);
        int boxRowStart = row - row % sqrt;
        int boxColStart = col - col % sqrt;

        for (int r = boxRowStart;
             r < (boxRowStart + sqrt) && r<board.length; r++)
        {
            for (int d = boxColStart;
                 d < (boxColStart + sqrt) & d < board.length; d++)
            {
                if (board[r][d] == num)
                {
                    return false;
                }
            }
        }

        // if there is no clash, it's safe
        return true;
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
}