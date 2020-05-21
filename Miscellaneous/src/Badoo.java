import java.math.BigDecimal;
import java.util.*;

public class Badoo {

    public static void main(String[] args) {
        List<Integer> mapping = new ArrayList<>();
        List<String> nums = new ArrayList<>();

        mapping = Arrays.asList(3,5,4,6,2,7,9,8,0,1);
        nums = Arrays.asList( "990","332", "32");
        solve(mapping, nums);
    }

    static class Compair implements Comparable<Compair> {
     Integer idx;
     BigDecimal value;
     String org;

        public Compair(int idx, BigDecimal value, String org) {
            this.idx = idx;
            this.value = value;
            this.org = org;
        }


        @Override
        public int compareTo(Compair compair) {
            if(this.value.equals(compair.value)) {
               return this.idx .compareTo(compair.idx);
            }
//            System.out.println("vals" + this.value + " " + compair.value + " " + this.idx);
            return this.value.compareTo(compair.value);
        }
    }
    private static void solve(List<Integer> mapping, List<String> nums) {

        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i<mapping.size(); i++) {
          map.put(mapping.get(i), i);
        }
        List<Compair> compairs = new ArrayList<>();
        for(int i = 0; i<nums.size(); i++) {
            String curr = nums.get(i);
//            String[] val = new String[curr.length()];
            StringBuilder val = new StringBuilder();

            for(int j = 0; j<curr.length(); j++) {
                int currIdx = Integer.parseInt(String.valueOf(curr.charAt(j)));
                int mapval = map.get(currIdx);
                val.append(mapval);
            }
           BigDecimal ex = new BigDecimal(val.toString());
//            System.out.println("this is ex "+ ex + " " + curr + " " + i);
            Compair comp = new Compair(i, ex, curr);

            compairs.add(comp);
        }
        int sz = compairs.size();
        bubbleSort(compairs);
        for(Compair c : compairs) {
            System.out.println(c.org);
        }
    }

   static  void bubbleSort(List<Compair> list)
    {
        int n = list.size();
        for (int i = 0; i < n-1; i++)
            for (int j = 0; j < n-i-1; j++)
                if (list.get(j).value.compareTo(list.get(j+1).value) == 1 )
                {
                    // swap arr[j+1] and arr[i]
                    Compair temp = list.get(j);
                    list.set(j, list.get(j+1));
                    list.set(j+1, temp);
                }

    }
}
