// Problem: C - Candles
// Contest: AtCoder - AtCoder Beginner Contest 107
// URL: https://atcoder.jp/contests/abc107/tasks/arc101_a
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
  int n, k;
  cin >> n >> k;
  vi a;

  forn(i, n) {
    int x;
    cin >> x;
    a.pb(x);
  }
  int i = 0;
  int j = 0;
  ll diff = 1e16 + 8;
  int piv = -1;
  REP(i, 1, n - 1) {
    if (a[i] >= 0 && a[i - 1] < 0) {
      piv = i - 1;
      break;
    }
  }
  for (i = 0; i + k - 1 < n; i++) {
    int j = i + k - 1;
    if (piv != -1 && piv >= i && piv <= i + k - 1) {
      ll dz = 0;
      if (abs(a[i]) <= a[j]) {
        dz = (abs(a[i]) * 2 * 1LL) + a[j];
      } else {
        dz = (a[j] * 2 * 1LL) + (-a[i]);
      }

      diff = min(diff, dz);
    } else {
      ll curr = 0;
      if (a[i] < 0) {
        curr = abs(a[i]) * 1LL;
      } else {
        curr = a[i + k - 1] * 1LL;
      }
      diff = min(diff, curr);
    }
  }
  cout << diff << endl;

  return 0;
}
