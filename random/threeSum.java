package random;

import java.util.*;

public class threeSum {
    /*
    It is not what you think when you pronounce it. :)
     */


  //  *OGBENI THIS IS ASS> I THANK GOD FOR CP IN YOUR LIFE>*
   static  List<List<Integer>> solutionSet = new ArrayList<>();

   static int a = 0;
    static int b = 0;
    static int c = 0;

    public static void threesum(int[] nums) {
        for (int i = 0; i < nums.length -1; i++) {
            a = nums[i];
            if (getSum(0, nums.length - 1, nums) + a == 0) {
                List<Integer> list = new ArrayList<>();
                list.add(a);
                list.add(b);
                list.add(c);
                solutionSet.add(list);
            }
        }
    }
    public static  int getSum(int top, int below, int[] nums) {
        int mid = (top + below) / 2;
      b = binarySearch(top, mid, nums);
      c = binarySearch(mid, below, nums);
      return b + c ;
    }

    public static  int binarySearch(int top, int below, int[] nums) {
        int presentElement = 0;
        if (top > below) {
            return presentElement;
        } else if (top == below) {
            return nums[top];
        } else {
            presentElement = getSum(top, below, nums);
        }
        return presentElement;
    }
}
