package CPManual;

public class NumberOfCoins {

    /*
    Find the number of coins needed to form the sum n using the coins given/
     */
    static int numberOfCoins(int[] coins, int n )  {
        int[] values = new int[n + 1];

        values[0] = 0;

        for(int x = 1; x <= n ; x++) {
            values[x] = Integer.MAX_VALUE;

            for (int c : coins) {
                if (x - c >= 0)
                values[x] = Math.min(values[x], values[x-c] + 1);
            }
        }
        return values[n];
     }

     public static void main(String[] args) {
        int [] coins = {1, 3,4};
        int solution = numberOfCoins(coins, 11);
        System.out.print(String.valueOf(solution));


     }
}
