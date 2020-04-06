package geeksforgeeks;

public class BubbleSort {


    public void bubbleSort(int[] arr) {
        for(int i = 0; i < arr.length - 1; i++) {
            for (int j = 0 ; j < i; j++ )
            if(arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i +  1];
                arr[i + 1] = temp;
            }
        }
    }
}
