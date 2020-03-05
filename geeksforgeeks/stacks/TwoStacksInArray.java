package geeksforgeeks.stacks;

public class TwoStacksInArray {
    int presentSize = 2;
    int[] array = new int[presentSize];
    int i1 = 0;

    private void push1(int x){
        iterateThroughI(x);

    }

    boolean iterateThroughI(int x) {
        int size = array.length;
        for (int i = 0; i < size / 2; i++) {
            if (array[i] == 0) {
               array[i] = x;
               return true;
            }
        }
        presentSize *= 2;

        int[] arrayTemp = new int[presentSize];
//
//        for (int j = 0, i = 0; j < size / 2, i < presentSize;  j-- )
        return true;

    }

}
