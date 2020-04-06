package geeksforgeeks;

public class SortedRotatedArray {

    static int findPivot(int low, int high, int[] array) {

        if (high < low) {
            return -1;
        }
        if (high == low) {
            return low;
        }

        int mid = low + (high - low) / 2;

        if (mid < high && array[mid] > array[mid + 1]) {
            return mid;
        }
        if (mid > low && array[mid] < array[mid - 1]) {
            return mid - 1;
        }
        if (array[mid] <= array[low]) {
           return findPivot(low, mid - 1, array);
        }
          return  findPivot(mid + 1, high, array);

    }

    static int pivotedArraySearch(int n, int key, int[] arr) {

        int pivot = findPivot(n-1, 0, arr);

        // If we didn't find a pivot, then
        // array is not rotated at all
        if (pivot == -1)
            return binarySearch(arr, 0, n-1, key);

        // If we found a pivot, then first
        // compare with pivot and then
        // search in two subarrays around pivot
        if (arr[pivot] == key)
            return pivot;
        if (arr[0] <= key)
            return binarySearch(arr, 0, pivot-1, key);
        return binarySearch(arr, pivot+1, n-1, key);
    }

    static int binarySearch(int[] arr, int low, int high, int key)
    {
        if (high < low)
            return -1;

        /* low + (high - low)/2; */
        int mid = (low + high)/2;
        if (key == arr[mid])
            return mid;
        if (key > arr[mid])
            return binarySearch(arr, (mid + 1), high, key);
        return binarySearch(arr, low, (mid -1), key);
    }

}
