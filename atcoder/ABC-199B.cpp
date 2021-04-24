// Problem: B - Intersection
// Contest: AtCoder - AtCoder Beginner Contest 199（Sponsored by Panasonic）
// URL: https://atcoder.jp/contests/abc199/tasks/abc199_b
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
bool overlap(int x1, int x2, int y1, int y2) {
  return (x1 >= y1 && x1 <= y2) || (x2 >= y1 && x2 <= y2) ||
         (y1 >= x1 && y1 <= x2) || (y2 >= x1 && y2 <= x2);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vi a(n), b(n);
  forn(i, n) { cin >> a[i]; }
  forn(i, n) cin >> b[i];

  int i = 1;
  int tp = a[0], bt = b[0];
  bool inv = false;
  while (i < n) {
    if (overlap(a[i], b[i], tp, bt)) {  // intersect
      tp = max(a[i], tp);
      bt = min(b[i], bt);
      //	cout << tp  << " " << bt << endl;
    } else {
      inv = true;

      break;
    }
    i++;
  }
  if (inv)
    cout << 0 << endl;
  else
    cout << bt - tp + 1 << endl;

  return 0;
}
