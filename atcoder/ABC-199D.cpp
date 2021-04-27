// Problem: D - RGB Coloring 2
// Contest: AtCoder - AtCoder Beginner Contest 199（Sponsored by Panasonic）
// URL: https://atcoder.jp/contests/abc199/tasks/abc199_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  ll ans = 1LL;
  if (m == 0) {
    forn(i, n) ans *= 3;
    cout << ans << endl;
  } else {
    vector<vector<int> > adj(n + 1, vector<int>());
    bool inv = false;
    forn(i, m) {
      int u, v;
      cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
      if (adj[u].size() > 2 || adj[v].size() > 2) inv = true;
    }
    if (inv) {
      cout << 0 << endl;
    } else {
      // connected comps;
      map<int, int> dn;
      int cc = 0;
      REP(i, 1, n) {
        if (dn.count(i)) continue;
        stack<int> st;
        cc++;
        st.push(i);
        while (!st.empty()) {
          int tp = st.top();
          st.pop();
          if (dn.count(tp)) continue;
          dn[tp] = 1;
          for (int ed : adj[tp]) {
            st.push(ed);
          }
        }
      }
      ans = 6 * cc;
      cout << ans << endl;
    }
  }
  return 0;
}
