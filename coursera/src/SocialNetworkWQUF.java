public class SocialNetworkWQUF {
    /**
     * For later:  my approach was to use an implementation of weighted Quick union find that had the size exposed;
     *in that way i could always know when a particular index in the size array of my UF implementation has a value equal to the
     * number of users which means that tree has unified totally?
     *
     */

    public class WeightedQuickUnionFindUF {
        private int[] id;
        private int[] sz;
        private int users;

        public WeightedQuickUnionFindUF(int N) {
            id = new int[N];
            sz = new int[N];
            users = N;

            for (int i = 0; i < N; i++) {
                id[i] = i;
            }
        }

        public int root(int i) {
            while(id[i] != i) i = id[i];
            return i;
        }

        private boolean connected(int p, int q) {
            return root(p) == root(q);
        }

        public void join(int p, int q) {
            int i = root(p);
            int j = root(q);
            if (i == j) return;
            if (sz[i] < sz[j]) {
                id[i] = j;
                sz[j] += sz[i];
                if (sz[j] >= users) {

                }
            }
            else { id[j] = i; sz[i] += sz[j]; }
        }

    }


}
