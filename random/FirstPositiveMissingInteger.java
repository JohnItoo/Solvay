package random;

import java.util.HashMap;
import java.util.Map;

public class FirstPositiveMissingInteger {
    Map<Integer, Integer> map = new HashMap<>();
    public int firstMissingPositive(int[] nums) {
        for (int i = 0; i < nums.length - 1; i++ ) {
            if(!map.containsKey(nums[i])) {
                map.put(nums[i], nums[i]);
            }
        }

        for (int i = 1; i < Integer.MAX_VALUE; i++) {
            if(!map.containsKey(i)) {
                return i;
            }
        }
        return 0;
    }
}
