// Problem: C. Sage's Birthday (hard version)
// Contest: Codeforces - Greedy #1
// URL: https://codeforces.com/group/pcTovAeVHg/contest/338449/problem/C
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

void greedyPattern() {
  int c = 3;
  vector<int> a;

  REP(i, 1, 5) {
    REP(j, 1, c) { a.pb(i); }
    c--;
    c = min(c, 1);
  }
  int ans = 0;
  a = {1, 7, 7, 7, 7, 7, 7};
  int sz = a.size();
  vector<int> res;
  do {
    int curr = 0;
    REP(i, 1, a.size() - 2) {
      if (a[i] < a[i - 1] && a[i] < a[i + 1]) curr++;
    }
    if (curr > ans) {
      ans = curr;
      res = a;
    }
  } while (next_permutation(a.begin(), a.end()));
  cout << ans << " " << a.size() << endl;
  do {
    int curr = 0;
    REP(i, 1, a.size() - 2) {
      if (a[i] < a[i - 1] && a[i] < a[i + 1]) curr++;
    }
    if (curr == ans) {
      forn(k, a.size()) { cout << a[k] << " "; }
      cout << endl;
    }
  } while (next_permutation(a.begin(), a.end()));
}

void solve() {
  int n;
  cin >> n;
  vi a(n);
  forn(i, n) cin >> a[i];
  sort(a.begin(), a.end());

  vi res(n);
  int i = 0, id = 1;

  while (id < n) {
    res[id] = a[i];
    id += 2;
    i++;
  }

  id = 0;

  while (id < n) {
    res[id] = a[i];
    id += 2;
    i++;
  }

  int ans = 0;

  REP(i, 1, n - 2) {
    if (res[i] < res[i + 1] && res[i] < res[i - 1]) ans++;
  }
  cout << ans << endl;
  forn(i, n) { cout << res[i] << " "; }
  cout << endl;
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
