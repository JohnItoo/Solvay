// Problem: D - Pair of Balls
// Contest: AtCoder - AtCoder Beginner Contest 216
// URL: https://atcoder.jp/contests/abc216/tasks/abc216_d
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

  int n, m;
  cin >> n >> m;
  map<int, vi> colpr;
  vector<stack<int> > vs(m + 4);

  set<int> readyCols;
  forn(i, m) {
    int k;
    cin >> k;
    vi a(k);

    forn(j, k) { cin >> a[j]; }
    stack<int> stk;
    for (int j = k - 1; j >= 0; j--) {
      stk.push(a[j]);
      if (j == 0) {
        colpr[a[j]].pb(i);
        if (colpr[a[j]].size() == 2) readyCols.insert(a[j]);
      }
    }
    vs[i] = stk;
  }
  int done = 0;

  while (!readyCols.empty()) {
    auto it = readyCols.begin();
    int readyCol = *it;
    readyCols.erase(it);
    vi here = colpr[readyCol];

    for (int kk = 0; kk <= 1; kk++) {
      int id = here[kk];
      vs[id].pop();
      done++;
      if (vs[id].size() != 0) {
        colpr[vs[id].top()].pb(id);
        if (colpr[vs[id].top()].size() == 2) {
          readyCols.insert(vs[id].top());
        }
      }
    }
  }

  if (done == 2 * n)
    cout << "Yes\n";
  else
    cout << "No\n";

  return 0;
}
