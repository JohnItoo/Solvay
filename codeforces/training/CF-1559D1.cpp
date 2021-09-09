//============================================================================
// Name        : template.cpp
// Author      :   $%U%$
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
#define _CRT_SECURE_NO_DEPRECATE  // suppress some compilation warning messages
                                  // (for VC++ users)
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
// To simplify repetitions/loops, Note: define your loop style and stick with
// it!
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define REP(i, a, b) \
  for (int i = int(a); i <= int(b); i++)  // a to b, and variable i is local!
#define forn(i, n) for (int i = 0; i < (n); i++)
#define TRvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000  // 2 billion
// If you need to recall how to use memset:
#define MEMSET_INF 127      // about 2B
#define MEMSET_HALF_INF 63  // about 1B
// memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path
// distances memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP
// memoization table memset(arr, 0, sizeof arr); // useful to clear array of
// integers

struct DSU {
  vi a;

  DSU(int n) {
    a.resize(n + 1);
    REP(i, 1, n) a[i] = i;
  }

  int root(int x) {
    while (a[x] != x) {
      x = a[x];
    }
    return x;
  }

  bool find(int x, int y) { return root(x) == root(y); }

  void connect(int x, int y) { a[root(x)] = root(y); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;

  DSU dsua(n);
  DSU dsub(n);

  forn(i, a) {
    int u, v;
    cin >> u >> v;
    dsua.connect(u, v);
  }

  forn(i, b) {
    int u, v;
    cin >> u >> v;
    dsub.connect(u, v);
  }

  vii prs;

  REP(i, 1, n) {
    REP(j, i + 1, n) {  // pairs of nodes

      bool finda = dsua.find(i, j);

      bool findb = dsub.find(i, j);

      if (!finda && !findb) {
        dsua.connect(i, j);

        dsub.connect(i, j);
        prs.pb({i, j});
      }
    }
  }
  cout << prs.size() << endl;
  for (auto pp : prs) {
    cout << pp.x << " " << pp.y << endl;
  }

  return 0;
}
