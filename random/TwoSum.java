package random;

import java.util.HashMap;


public class TwoSum {
    public  static int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int[] solution = new int [2];
        for (int i = 0; i < nums.length; i++) {
            if ( map.containsKey(target - nums[i])) {
                solution[0] = i;
                solution[1] = map.get(target - nums[i]);
                return solution;
            }
            map.put(nums[i], i);
        }
        return solution;
    }
}
