// Problem: L. All the Vowels Please
// Contest: Codeforces - Math #1
// URL: https://codeforces.com/group/pcTovAeVHg/contest/338455/problem/L
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
  int k;
  cin >> k;
  for (int i = 1; i * i <= k; i++) {
    if (k % i) continue;
    if (i < 5 || k / i < 5) continue;
    string s;
    string v = "aeiou";
    int st = 0;
    while (s.size() < k) {
      for (int q = 0; q < i; q++) {
        int val = (st + q) % 5;
        s.pb(v[val]);
      }
      st++;
      st %= 5;
    }
    cout << s << endl;
    return;
  }
  cout << -1 << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  // cin >> tc;
  int count = 1;
  while (tc--) {
    // cout << "Case #" << count << ": "; //CODEJAM/KICKSTART
    count++;
    solve();
  }
  return 0;
}
