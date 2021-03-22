// Problem: C - Build Stairs
// Contest: AtCoder - AtCoder Beginner Contest 136
// URL: https://atcoder.jp/contests/abc136/tasks/abc136_c
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
  int n;
  cin >> n;
  vi h(n);
  forn(i, n) cin >> h[i];
  vi mx(n), mn(n);
  int bg = -1;
  forn(i, n) {
    bg = max(bg, h[i]);
    mx[i] = bg;
  }
  int mv = n - 1;
  int sm = 1e9 + 3;
  while (mv >= 0) {
    sm = min(sm, h[mv]);
    mn[mv] = sm;
    mv--;
  }
  mv = n - 1;
  bool fd = true;
  while (mv >= 0) {
    if (mx[mv] - 1 > mn[mv]) {
      fd = false;
      break;
    }
    mv--;
  }
  if (fd)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
