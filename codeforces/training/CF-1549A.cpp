// Problem: A. Web of Lies
// Contest: Codeforces - Codeforces Round #736 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1548/A
// Memory Limit: 256 MB
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
  vector<int> edges(n + 5, 0);
  vector<int> greats(n + 5, 0);
  vi orgedg, orggr;

  forn(i, m) {
    int u, v;
    cin >> u >> v;

    edges[u]++;
    edges[v]++;
    if (u > v) {
      greats[u]++;
    } else {
      greats[v]++;
    }
  }
  orgedg = edges;
  orggr = greats;
  int organs;
  int ans = 0;
  REP(i, 1, n) {
    if (edges[i] == greats[i]) ans++;
  }
  organs = ans;
  int q;
  cin >> q;
  while (q--) {
    int a;
    cin >> a;
    if (a == 1) {
      int u, v;
      cin >> u >> v;
      if (edges[u] == greats[u]) ans--;
      if (edges[v] == greats[v]) ans--;
      edges[u]++;
      edges[v]++;
      if (u > v) {
        greats[u]++;
        if (edges[u] == greats[u]) ans++;
      } else {
        greats[v]++;
        if (edges[v] == greats[v]) ans++;
      }
    } else if (a == 2) {
      int u, v;
      cin >> u >> v;

      if (u > v) {
        if (edges[u] == greats[u]) {
          ans--;
        }
        greats[u]--;
      } else {
        if (edges[v] == greats[v]) {
          ans--;
        }
        greats[v]--;
      }
      edges[u]--;
      edges[v]--;
      if (edges[u] == greats[u]) ans++;
      if (edges[v] == greats[v]) ans++;

    } else {
      cout << ans << endl;
    }
  }
  return 0;
}
