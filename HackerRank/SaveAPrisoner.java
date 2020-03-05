package HackerRank;

public class SaveAPrisoner {

    public int saveThePrisoner(int n, int m, int s) {
        return s + ( s + m % n );
    }
}
