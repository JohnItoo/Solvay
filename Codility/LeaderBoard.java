import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LeaderBoard {

    private HashMap<Integer, Integer> leaderBoard = new HashMap<>();

    public LeaderBoard() {}

    public float add_score(int player_id, int score) {
        int presentScore = 0;
        if(isOnLeaderBoard(player_id)) {
            int current = leaderBoard.get(player_id);
            presentScore = current + score;
        } else {
            presentScore = score;
        }
        leaderBoard.put(player_id, presentScore);

        return (float) presentScore;
    }

    public List<Integer> top(int max) {
        List<Integer> result = new ArrayList<>();
        leaderBoard.entrySet().stream()
                .sorted(Map.Entry.<Integer, Integer>comparingByValue()
                        .reversed()).forEachOrdered( x -> result.add(x.getKey()));
        try {
            return  result.subList(0, max);
        } catch (Exception e) {
            System.out.println("Max is too big? Returning top ID");
        }
       return result.subList(0, 1);
    }

    public void reset(int player_id) {
        if(isOnLeaderBoard(player_id)) {
            leaderBoard.put(player_id,0);
        }
    }

    private boolean isOnLeaderBoard(int player_id) {
        return leaderBoard.containsKey(player_id);
    }

}