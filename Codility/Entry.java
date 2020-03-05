import java.util.List;

public class Entry {
    public  static void main(String[] args) {
        LeaderBoard leaderBoard = new LeaderBoard();

        leaderBoard.add_score(2, 50);
        leaderBoard.add_score(5,100);
        leaderBoard.add_score(6,100);

        List<Integer> ans = leaderBoard.top(3);

        for (int i :
                ans) {
            System.out.println(i);
        }
    }
}

