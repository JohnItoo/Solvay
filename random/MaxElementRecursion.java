package random;

public class MaxElementRecursion {

    /* Binary recursion
     */

    public static int maxElement(int[] data) {
       return findMax(data, 0, data.length - 1);
    }

    private static int findMax(int[] data, int low, int high) {
        int tempMax = 0;
        if(low > high) {
            return tempMax;
        } else if (low == high) {
            return Math.max(tempMax, data[low]);
        } else {
            int mid = (high + low) / 2;
            tempMax = Math.max(findMax(data, low, mid), findMax(data, mid + 1, high));
        }
        return tempMax;
    }

    public static void main (String[] args) {
        int[] data = {1,2,4,5,66,6,4,2, 49, 90, 4};
        System.out.println("The max element in the array is : " + maxElement(data));
    }
}
