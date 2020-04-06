package geeksforgeeks;

public class RotationCountInRotatedSortedArray {

    /* my solution uses the pivot so where previous element is larger than
    next element i return the index of the small element.
     */

    static int getCount(int[] arr) {
        for (int i = 0; i <arr.length; i++) {
            if(arr[i] > arr[i + 1]) {
                return i +1;
            }
        }
        // we will never reach here i think so;
        return 0;
    }

    //The geek for geek solution O(n) is basically the same idea but finishes the loop

    static int getCountRotations(int[] arr)  {
        int min_value = arr[0];
        int min_index = 0;

        for(int i = 1; i< arr.length; i++) {
            if(min_value > arr[i]) {
                min_value = arr[i];
                min_index = i;
            }
        }
        return min_index;
    }

    // The O(logn)

    static int getCountRotationBinarySearch(int[]arr, int low, int high) {
        //array is not rotated
        if (high < low) {
            return  -1;

        }

        //one element left
        if (high == low) {
            return low;
        }

        int mid = low + (high - low) / 2;

        //if mid + 1 is the pivot/minimum element
        if (mid < high && arr[mid + 1] < arr[mid]) {
            return  mid + 1;
        }

        //if mid is the min element
        if(mid < high && arr[mid] < arr[mid - 1]) {
            return  mid;
        }

        //make decision to go left or right

        //go left if element on low is greater tha
        if(arr[high] > arr[mid]) {
           return getCountRotationBinarySearch(arr, low, mid -1);
        }
        return getCountRotationBinarySearch(arr, mid + 1, high );
    }

}

