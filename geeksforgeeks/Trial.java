package geeksforgeeks;

public class Trial {

    private static int ans = 0;
    private static int duc = 0;

    public static void main(String[] args) {
        String[][] array = {
                {"1", "0", "1", "1", "1"},
                {"1", "0", "1", "1", "1"},
                {"1", "1", "1", "1", "1"},
                {"1", "0", "0", "1", "0"}
        };

        System.out.println(solve(array));
    }

    private static int solve(String[][] a) {
        for (int i = 0; i < a.length; ++i) {
            for (int j = 0; j < a[i].length; ++j) {
//                traverse(a, 0, i, j, false);
                int f = i ; int b = j;
                while(!a[i][b].equals("0") &&  !a[i][b].equals("0"))
                count(a, i,j);
            }
            duc = Math.max(ans, duc);
            ans = 0;
        }
        return duc;
    }

    private static void traverse(String[][] a, int sum, int i, int j, boolean inOffice) {
        if (i < 0 || i >= a.length || j < 0 || j >= a[i].length || a[i][j].equals("0")) {
            return;
        }

        if (!inOffice) {
            ans += 1;
            inOffice = true;
        }
        a[i][j] = "0";
        traverse(a, sum, i - 1, j, inOffice);
        traverse(a, sum, i + 1, j, inOffice);
        traverse(a, sum, i, j + 1, inOffice);
    }

    public static void count(String[][] grid, int i , int j) {
        if(i<0 || i >= grid.length || j < 0 || j >= grid[i].length || grid[i][j].equals("0"))      {return; }
        if(grid[i][j].equals("1")) {
            ans += 1;
           grid[i][j] = "0";
        }
//        count(grid, i-1, j);
        count(grid, i+1, j);
        count(grid, i, j+1);
    }
}
