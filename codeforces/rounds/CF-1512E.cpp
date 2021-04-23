// Problem: E. Permutation by Sum
// Contest: Codeforces - Codeforces Round #713 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1512/E
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
  int tc;
  cin >> tc;
  while (tc--) {
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    int ct = (r - l) + 1;
    int sm = (n * (n + 1)) / 2;
    // if(n < s) {
    // cout << -1 << endl;
    // continue;
    // }
    // dp[0][0] = 0;
    int rw = s + 1, cl = ct + 1;
    int mx = 1e9 + 3;
    vector<vector<int> > dp(rw, vector<int>(cl, mx));
    forn(i, cl) { dp[0][i] = 0; }
    //

    forn(i, rw) { dp[i][0] = 0; }

    for (int i = 0; i <= s; i++) {
      for (int j = 1; j <= ct; j++) {
        if (j == 1)
          dp[i][j] = i;
        else if (i >= j && dp[i - j][j - 1] != mx) {
          dp[i][j] = i - j;
        }
      }
    }
    if (dp[s][ct] == mx) {
      cout << -1 << endl;
    } else {
      int w = s;
      int count = ct;
      map<int, int> mp;
      forn(i, n + 5) {
        forn(j, ct + 5) cout << dp[i][j] << " ";
        cout << endl;
      }
      while (count > 0) {
        int val = dp[w][count];
        //   	cout << val << " " << w << " " << count << " "<< endl;
        w -= val;
        count--;
        mp[val]++;
      }

      map<int, int> dn;

      int idx = 1;
      REP(j, 1, n) {
        if (idx == l) break;
        if (mp.count(j)) continue;
        dn[j]++;
        cout << j << " ";
        idx++;
      }
      for (auto ii : mp) {
        cout << ii.first << " ";
        idx++;
      }

      for (int j = 1; j <= n; j++) {
        if (mp.count(j) || dn.count(j)) continue;
        cout << j << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
