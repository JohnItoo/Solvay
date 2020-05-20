package codejam;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Scheduling {

    static BufferedReader br;
    static StringTokenizer tokenizer;

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        int tc = nextInt();
        for (int i = 1; i <= tc; i++) {
            System.out.print("Case #" + i + ": ");
            solve();
        }
    }
    static class Period implements Comparable<Period> {
        int idx;
        int key;
        int value;
        public Period(Integer key, Integer value, Integer idx) {
            this.key = key;
            this.value = value;
            this.idx = idx;
        }

        public int getKey() {
            return key;
        }

        public int getValue() {
            return value;
        }

        @Override
        public int compareTo(Period period) {
            return Integer.compare(this.getKey(), period.getKey());
        }
        public int getIdx() {
            return  idx;
        }
    }

    static void  solve() throws Exception{
        int times;
        times = nextInt();
        List<Period> pairs = new ArrayList<>();
        char[] map = new char[times];
        for(int t = 0; t<times; t++) {
            int a ; int b ;
            a = nextInt(); b = nextInt();
            Period period = new Period(a, b, t);
            pairs.add(period);
        }

        Collections.sort(pairs);
        boolean isImpossible = false;
        char curr = 'C'; int Cend = pairs.get(0).getValue(); int Jend = 0;
        map[pairs.get(0).getIdx()] = 'C';

        for(int i = 1; i< pairs.size(); ++i) {
          if(pairs.get(i).getKey() < Cend  && pairs.get(i).getKey() >= Jend) {
              map[pairs.get(i).getIdx()] = 'J';
              Jend = pairs.get(i).getValue();
              continue;
          }
           if(pairs.get(i).getKey() < Jend  && pairs.get(i).getKey() >= Cend) {
              map[pairs.get(i).getIdx()] = 'C';
              Cend = pairs.get(i).getValue();
              continue;
          }
           if(pairs.get(i).getKey() >= Cend ) {
              map[pairs.get(i).getIdx()] = 'C';
              Cend = pairs.get(i).getValue();
              continue;
          }

          if(pairs.get(i).getKey() >= Jend ) {
              map[pairs.get(i).getIdx()] = 'J';
              Jend = pairs.get(i).getValue();
              continue;
          }

           isImpossible = true;
           break;
      }
      if(isImpossible) { System.out.print("IMPOSSIBLE \n");}
      else {System.out.print(String.valueOf(map) + "\n");}
    }
        public static String next() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                String line = br.readLine();
                if (line == null)
                    throw new IOException();
                tokenizer = new StringTokenizer(line);
            }
            return tokenizer.nextToken();
        }

        public static int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
}