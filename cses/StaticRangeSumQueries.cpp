#include <bits/stdc++.h>
using namespace std;

vector<int> tree;

int f(int node, int low, int high, int queryLow, int queryHigh) {
    if(queryLow <= low && high <= queryHigh) return tree[node]; // if lwo && high is completely within query range
    if(high <= queryLow || queryHigh <= low) return 0;
    int RightOfLeftMostChild = (low + high) / 2;
    return f(2*node, low, RightOfLeftMostChild, queryLow, queryHigh) + f(2*node+1, RightOfLeftMostChild+1, high, queryLow, queryHigh);
}

int main() {
    int n, q; cin >> n >> q;
     vector<int> a(n);
     for(int i = 0; i < n; i++) cin >> a[i];
    while(__builtin_popcount(n)  != 1) {
       n++;
       a.push_back(0);
    }
    tree.resize(2*n);
    //BUILD TREE

    

    for(int i = (2*n)-1,  j = n-1; i >=n; i--, j--) {
        tree[i] = a[j];
    }
    for(int i = n-1; i >= 1; i--) {
        tree[i] = tree[2*i] + tree[2*i+1];
    }

    for(int i = 0; i < q; i++) {
        int low, high; cin >> low >> high;
        low--;
        high--;
        cout << f(1, 0, n-1, low, high) << "\n";
    }

    return 0;
}