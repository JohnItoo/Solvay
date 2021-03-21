// Problem: A1. Binary Table (Easy Version)
// Contest: Codeforces - Codeforces Round #684 (Div. 1)
// URL: https://codeforces.com/contest/1439/problem/A1
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    forn(i, n) { cin >> grid[i]; }
    vii res;
    for(int i = 0; i + 1 <= n - 1; i+=2) {
      for (int j = 0; j + 1 <= m - 1; j+=2) {
        map<ii, int> zeros;
        map<ii, int> ones;
        for (int k = i; k <= i + 1; k++) {
          for (int l = j; l <= j + 1; l++) {
            if (grid[k][l] == '0') {
              zeros[mp(k, l)] = 1;
            } else {
              ones[mp(k, l)] = 1;
            }
          }
        }
        while (ones.size() > 0) {
          int sz = ones.size();
           cout << sz << endl;
          int one = 0;
          if (sz == 4) {
            one = 3;
          } else if (sz == 3) {
            one = 3;
          } else if (sz == 2) {
            one = 1;
          } else {
            one = 1;
          }
          set<ii> remz;
          set<ii> remo;
          int zero = 3 - one;
          for (auto idx : ones) {
            if (one == 0) break;
            ii val = idx.x;
            remo.insert(val);
            one--;
          }
          for (auto idx : zeros) {
            if (zero == 0) break;
            ii val = idx.x;
            remz.insert(val);
            zero--;
          }

          for (auto it = remz.begin(); it != remz.end(); ++it) {
            ii pr = *it;
            zeros.erase(pr);
            ones[pr] = 1;
            res.pb(pr);
            grid[pr.x][pr.y] = '1';
          }

          for (auto it = remo.begin(); it != remo.end(); ++it) {
            ii pr = *it;
            ones.erase(pr);
            res.pb(pr);
            grid[pr.x][pr.y] = '0';
            zeros[pr] = 1;
          }
        }
      }
    }
    int ans = res.size() / 3;
    cout << ans << "\n";

    forn(i, ans) {
      forn(j, 3) {
        int idx = 3 * i + j;
        cout << res[idx].x + 1 << " " << res[idx].y + 1 << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
