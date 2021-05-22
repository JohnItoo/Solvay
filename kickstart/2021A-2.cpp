// Problem: L Shaped Plots
// Contest: Google Coding Competitions - Round A 2021 - Kick Start 2021
// URL:
// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140/000000000068c509
// Memory Limit: 1024 MB
// Time Limit: 60000 ms
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
  int count = 1;
  while (tc--) {
    cout << "Case #" << count << ": ";
    count++;
    int n, m;
    cin >> n >> m;
    vector<vector<int> > grid(n, vector<int>(m, 0));
    forn(i, n) {
      forn(j, m) { cin >> grid[i][j]; }
    }
    vector<vector<int> > r(n, vector<int>(m, 0));
    vector<vector<int> > l(n, vector<int>(m, 0));
    vector<vector<int> > u(n, vector<int>(m, 0));
    vector<vector<int> > d(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
      if (grid[i][m - 1]) r[i][m - 1] = 1;
      for (int j = m - 2; j >= 0; j--) {
        if (grid[i][j]) {
          if (r[i][j + 1]) {
            r[i][j] = r[i][j + 1] + 1;
          } else {
            r[i][j] = 1;
          }
        }
      }
    }

    forn(i, n) {
      if (grid[i][0]) l[i][0] = 1;
      for (int j = 1; j < m; j++) {
        if (grid[i][j]) {
          if (l[i][j - 1]) {
            l[i][j] = l[i][j - 1] + 1;
          } else {
            l[i][j] = 1;
          }
        }
      }
    }

    forn(j, m) {
      if (grid[0][j]) u[0][j] = 1;
      for (int i = 1; i < n; i++) {
        if (grid[i][j]) {
          if (u[i - 1][j]) {
            u[i][j] = u[i - 1][j] + 1;
          } else {
            u[i][j] = 1;
          }
        }
      }
    }

    forn(j, m) {
      if (grid[n - 1][j]) d[n - 1][j] = 1;
      for (int i = n - 2; i >= 0; i--) {
        if (grid[i][j]) {
          if (d[i + 1][j]) {
            d[i][j] = d[i + 1][j] + 1;
          } else {
            d[i][j] = 1;
          }
        }
      }
    }
    int ans = 0;
    int fir = 0;

    forn(i, n) {
      forn(j, m) {
        if (min(u[i][j], r[i][j]) >= 2 && max(u[i][j], r[i][j]) >= 4) {
          fir = min(u[i][j] / 2, r[i][j]);
          if (fir >= 2) {
            ans += fir - 1;
          }
          fir = min(u[i][j], r[i][j] / 2);
          if (fir >= 2) {
            ans += fir - 1;
          }
        }

        if (min(u[i][j], l[i][j]) >= 2 && max(u[i][j], l[i][j]) >= 4) {
          fir = min(u[i][j] / 2, l[i][j]);
          if (fir >= 2) {
            ans += fir - 1;
          }
          fir = min(u[i][j], l[i][j] / 2);
          if (fir >= 2) {
            ans += fir - 1;
          }
        }

        if (min(d[i][j], l[i][j]) >= 2 && max(d[i][j], l[i][j]) >= 4) {
          fir = min(d[i][j] / 2, l[i][j]);
          if (fir >= 2) {
            ans += fir - 1;
          }
          fir = min(d[i][j], l[i][j] / 2);
          if (fir >= 2) {
            ans += fir - 1;
          }
        }

        if (min(d[i][j], r[i][j]) >= 2 && max(d[i][j], r[i][j]) >= 4) {
          fir = min(d[i][j] / 2, r[i][j]);
          if (fir >= 2) {
            ans += fir - 1;
          }
          fir = min(d[i][j], r[i][j] / 2);
          if (fir >= 2) {
            ans += fir - 1;
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
