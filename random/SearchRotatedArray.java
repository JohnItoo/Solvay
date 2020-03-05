package random;

public class SearchRotatedArray {

    private int binarySearch(int top, int bottom, int[] nums, int target) {
         if (top > bottom) {
             return -1;
         }
         int mid = top + (bottom - top) / 2;
         if(nums[mid] == target) {
             return mid;
         }
         if (nums[top] <= nums[mid]) {
             if (nums[top] <= target && target < nums[mid]) {
                 binarySearch(top, mid -1, nums, target);
             } else {
                 binarySearch(mid+1 , bottom, nums, target);
             }
         } else {
             if(nums[mid] < target && target >= nums[bottom]) {
                 binarySearch(mid + 1, bottom, nums, target);
             } else {
                 binarySearch(top, mid -1 , nums, target);
             }
         }
         return -1;
    }
}
