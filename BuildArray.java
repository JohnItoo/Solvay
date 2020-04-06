public class BuildArray {
    public static void main(String[] args) {
        String[][] grid =
                {
                        {"A", "B", "C"},
                        {"D", "E", "F"},
                        {"G", "H", "I"}
                };
        for (int row = 0; row < 3; row++) {
            System.out.println(' ');
            for (int column = 0; column < 3; column++) {
                System.out.print(grid[row][column] + " ");
            }
        }
    }
}
