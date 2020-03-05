public class WeightedQuickUnionFindUF {
    private int[] id;
    private int[] sz;

    public WeightedQuickUnionFindUF(int N) {
        id = new int[N];
        sz = new int[N];

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
        if (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
        else { id[j] = i; sz[i] += sz[j]; }
    }

}
