// Problem: D - Strange Lunchbox
// Contest: AtCoder - Sciseed Programming Contest 2021（AtCoder Beginner Contest
// 219） URL: https://atcoder.jp/contests/abc219/tasks/abc219_d Memory Limit:
// 1024 MB Time Limit: 2000 ms
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
#define INF 20000000  // 2 billion
// If you need to recall how to use memset:
#define MEMSET_INF 127      // about 2B
#define MEMSET_HALF_INF 63  // about 1B
// memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path
// distances memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP
// memoization table memset(arr, 0, sizeof arr); // useful to clear array of
// integers
int dp[305][305];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int tak, tai;
  cin >> tak >> tai;

  vector<int> taks, tais;
  vii prs;

  forn(i, n) {
    int x, y;
    cin >> x >> y;
    taks.pb(x);
    tais.pb(y);
  }

  memset(dp, MEMSET_INF, sizeof dp);

  dp[0][0] = 0;

  for (int i = 1; i <= n; i++) {
    for (int a = tak; a >= 0; a--) {
      for (int b = tai; b >= 0; b--) {
        int takcost = taks[i - 1];
        int taicost = tais[i - 1];

        int maxtak = max(0, a - takcost);
        int maxtai = max(0, b - taicost);
        int comp = dp[maxtak][maxtai] + 1;
        //  cout << i << " " << a << " " << b << " " << comp << endl;
        dp[a][b] = min(dp[a][b], comp);
        // cout << a << " " << b << " " << i << " " << dp[i][a][b] << endl;
      }
    }
  }

  if (dp[tak][tai] >= MEMSET_INF) {
    cout << -1;

  } else {
    cout << dp[tak][tai] << endl;
  }

  return 0;
}
