// Problem: D. Phoenix and Socks
// Contest: Codeforces - Codeforces Global Round 14
// URL: https://codeforces.com/problemset/problem/1515/D
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
    int n, l, r;
    cin >> n >> l >> r;
    map<int, int> lef;
    map<int, int> rig;

    forn(i, l) {
      int x;
      cin >> x;
      lef[x]++;
    }
    forn(i, r) {
      int x;
      cin >> x;
      rig[x]++;
    }
    int prs = 0;

    for (auto ii : lef) {
      int val = ii.x;
      if (rig.count(val) != 0) {
        if (rig[val] < lef[val]) {
          lef[val] -= rig[val];
          rig[val] = 0;
        } else if (rig[val] == lef[val]) {
          rig[val] = 0;
          lef[val] = 0;
        } else {
          rig[val] -= lef[val];
          lef[val] = 0;
        }
      }
    }

    int cost = 0;
    for (auto ii : lef) {
      if (ii.y > 1) {
        int hr = ii.y / 2;
        cost += hr;
        lef[ii.x] = (ii.y & 1);
      }
    }

    for (auto ii : rig) {
      if (ii.y > 1) {
        int hr = ii.y / 2;
        cost += hr;
        rig[ii.x] = (ii.y & 1);
      }
    }
    cout << cost << " ; ";
    int reml = 0;
    int remr = 0;

    for (auto ii : lef) {
      if (ii.y > 0) {
        reml++;
      }
    }
    for (auto ii : rig) {
      if (ii.y > 0) {
        remr++;
      }
    }
    int mid = (reml + remr) / 2;

    cost += mid;

    cout << cost << endl;
  }
  return 0;
}
