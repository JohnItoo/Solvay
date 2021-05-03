// Problem: C. Fence Painting
// Contest: Codeforces - Codeforces Round #699 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1481/C
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
// Last color must be a color that is desired
//
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vi a(n), b(n), pt(m);
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    forn(i, m) cin >> pt[i];  // 1th index
    map<int, int> has;
    vector<vector<int> > need(n + 1, vector<int>());
    vi offset(n + 1, 0);
    int tots = 0;
    forn(i, n) {
      if (a[i] != b[i]) {
        need[b[i]].pb(i);
        tots++;
      } else {
        has[a[i]] = i;
      }
    }

    int lastcol = pt[m - 1];

    vector<int> res(m);
    if (need[lastcol].size() == 0 && has.count(lastcol) == 0) {
      cout << "NO\n";  // last col is impossible.
    } else {
      // not enough .. i.e tots != 0 : NO
      forn(i, m) {
        int col = pt[i];  // 1th index

        if (offset[col] < need[col].size()) {
          res[i] = need[col][offset[col]] + 1;
          a[res[i] - 1] = col;
          offset[col]++;
        } else if (offset[col] >= need[col].size()) {
          int idx = need[lastcol].size() - 1;
          int x = need[lastcol][idx];
          a[x] = lastcol;
          res[i] = x + 1;
        }
      }
      bool vld = true;
      forn(i, n) { vld &= (a[i] == b[i]); }
      if (vld) {
        cout << "YES\n";
        forn(i, m) cout << res[i] << " ";
        cout << endl;
      } else {
        cout << "NO\n";
      }
    }
    return 0;
  }

  return 0;
}
