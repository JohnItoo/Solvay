// Problem: B. Running for Gold
// Contest: Codeforces - Codeforces Global Round 15
// URL: https://codeforces.com/contest/1552/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

bool isgreater(vi a, vi b) {
  int act = 0, bct = 0;
  forn(i, 5) {
    if (a[i] < b[i]) {
      act++;
    } else {
      bct++;
    }
  }
  return act > bct;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<vi> vals(n, vector<int>(5));
    set<int> cant;
    set<int> can;

    forn(i, n) {
      forn(j, 5) { cin >> vals[i][j]; }
      can.insert(i);
    }

    int tent = -1;

    while (cant.size() < n && can.size() > 0) {
      int pos = *can.begin();
      can.erase(pos);
      bool vld = true;
      while (can.size() > 0 && vld) {
        int curr = *can.begin();
        if (isgreater(vals[pos], vals[curr])) {
          can.erase(curr);
        } else {
          cant.insert(pos);
          vld = false;
          break;
        }
      }
      if (vld) {
        tent = pos;
        break;
      }
    }

    if (tent != -1) {
      forn(i, n) {
        if (i == tent) continue;
        if (isgreater(vals[i], vals[tent])) {
          tent = -1;
          break;
        }
      }
      tent = tent == -1 ? tent : tent + 1;
      cout << tent << endl;
    } else {
      cout << tent << endl;
    }
  }
  return 0;
}
