package HackerRank;

/*
X1 + V1x = X2 + V2x
 */

public class Kangaroo {

    public String kangaroo(int x1, int v1, int x2, int v2) {
        if (canMeetAtSomePoint(x1, v1, x2, v2)) {
            return "YES";
        } else {
            return "NO";
        }
    }

    private boolean canMeetAtSomePoint(int x1, int v1, int x2, int v2) {
        if (x2 - x1 > 0 && v1 - v2 > 0) {
            return  (x2 - x1) / (v1 - v2) > 0 &&  (x2 - x1) % (v1 - v2) == 0;
        } else {
            return false;
        }
    }


}