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
vector<int> dsu, dsub;
int flag = 1;

int root(int x) {
  if (flag == 1) {
    while (dsu[x] != x) {
      x = dsu[x];
    }
    return x;
  } else {
    while (dsub[x] != x) {
      x = dsub[x];
    }
    return x;
  }
}

void connect(int x, int y) {
  int froot = root(x);
  int sroot = root(y);
  if (flag == 1) {
    dsu[froot] = sroot;
  } else {
    dsub[froot] = sroot;
  }
}

bool find(int x, int y) { return root(x) == root(y); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;

  dsu.resize(n + 3);
  dsub.resize(n + 3);

  REP(i, 1, n) {
    dsu[i] = i;
    dsub[i] = i;
  }

  forn(i, a) {
    int u, v;
    cin >> u >> v;
    connect(u, v);
  }

  flag = 2;
  forn(i, b) {
    int u, v;
    cin >> u >> v;
    connect(u, v);
  }

  vii prs;

  REP(i, 1, n) {
    REP(j, i + 1, n) {  // pairs of nodes
      flag = 1;
      bool finda = find(i, j);

      flag = 2;
      bool findb = find(i, j);

      if (!finda && !findb) {
        flag = 1;
        connect(i, j);
        flag = 2;
        connect(i, j);
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
