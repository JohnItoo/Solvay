package HackerRank;

public class SherlockAndDivisors {
   public static int divisors(int n) {
       int divided = 0;
        for (int start = 1; start * start <= n; start++) {
            if ( n % start == 0)  {
                if(isDivisibleBy2(start)) {
                    divided++;
                }
                if(n / start != start && isDivisibleBy2(n / start)) {
                    divided++;
                }
            }
        }
        return divided;
    }

    private static boolean isDivisibleBy2(int n) {
        return n % 2 == 0;
    }
}