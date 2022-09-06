// Problem: C. Min-Max Array Transformation
// Contest: Codeforces - Educational Codeforces Round 134 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1721/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

//============================================================================
// Name        : BXK
// Author      : Template
// Version     :
// Copyright   : Who was here
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
void solve() {
  int n;
  cin >> n;
  vi a(n);
  forn(i, n) cin >> a[i];
  vi b(n);
  forn(i, n) cin >> b[i];

  int up = n - 1;
  int rtdown = n - 1; int ltdown = n - 1;
  vi dmin(n);
  vi dmax(n);

  while (up >= 0) {
    while (ltdown > 0 && b[ltdown - 1] >= a[up]) ltdown--;
    dmin[up] = b[ltdown] - a[up];
    dmax[up] = b[rtdown] - a[up];
    bool ent = false;
    while(ltdown > 0 && b[ltdown-1] >= a[up]) {
    	ltdown--;
    	ent = true;

    }
    up--;
    if(up < ltdown) {
    	ltdown = up;
    	rtdown = up;
    }
   
  }
  forn(i, n) { cout << dmin[i] << " "; }
  cout << endl;
  forn(i, n) { cout << dmax[i] << " "; }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  int count = 1;
  while (tc--) {
    // cout << "Case #" << count << ": "; //CODEJAM/KICKSTART
    count++;
    solve();
  }
  return 0;
}
