package random;

public class RecursiveProductOfTwoNumbersWithAdditionandSubtraction {

    public static int sum(int n, int m) {
        if (n == 0) {
            return 0;
        } else {
            return  sum(n - 1, m) + m;
        }
    }


}
