package CPManual;

import java.util.*;

public class AmortizedAnalysis {

    public static void main(String[] args) {

    }

    public static int[] twoSum(int[] arr, int target ) {
        Arrays.sort(arr);

        /** So because you know it is sorted if the guy on the right gives a sum that is greater than you just move to the left a bit.
         *
         */
        int n = arr.length;
        int[] s = new int[2];

        for (int i = 0, j = n - 1; i <= j; i++, j++) {

            if (arr[i] + arr[j] == target) {
                s[0] = i;
                s[1] = j;
                /*
                s[0] = arr[i];
                s[1] = arr[j];
                 */
            }
             if (arr[i] + arr[j] > target) {
                 j--;
             }
            if (arr[i] + arr[j] < target) {
                 i++;
            }
        }
        return s;
    }

    /*
    Why do this when i can do  that ^^^.. Well except if i am copying the internals for Binary search
     */
    public  static int twoSumBinarySearch(int[] arr , int target) {
          int solution = -1;
           Arrays.sort(arr);
        for (int i = 0; i < arr.length; i++) {
            int s =   binarySearch(arr, target - arr[i]);
           if (s  != -1)  {
               //return arr[i]  &&s ;
           }
        }
        return solution;
    }

    private static int binarySearch(int[]arr, int t) {
        return internals(0, arr.length - 1, arr, t);

    }

    private static int internals (int top, int bottom, int [] arr, int t) {

        if (top > bottom) {
            return  -1;
        }
        int mid = top + (bottom - top) / 2;

        if (arr[mid] == t ) {
            return t;
        }
        if (arr[mid] > t) {
           return internals(top, mid -1, arr, t);
        }

        if (arr[mid] < t) {
            return internals(mid + 1, bottom, arr, t);
        }
        return -1;
    }

    /*
      x< 0, x= 0  is equal to 0 in memo array
      x > 0 = twoSearch(t - c)
      t -> 1 to target

     */

    public static void threeSumAnalysis(int []arr, int target) {
        int[] memo = new int[arr.length];
        //Sort Arrray here
        Arrays.sort(arr);

        for (int x = 0; x <= target ; x++) {
             for (int c : arr) {
             int[] intermediary =   twoSum(arr, (target -c));
             
             //intermediary and c should be stored as the three values
                 //if intermediary are non zero values na the answer be that.
             }
        }

    }

}
