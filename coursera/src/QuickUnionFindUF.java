public class QuickUnionFindUF {
    private int[] id;


    public QuickUnionFindUF(int N) {
        id = new int[N];

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
        int qRoot = root(q);
        int pRoot = root(p);
        id[pRoot] = qRoot;
    }
}
