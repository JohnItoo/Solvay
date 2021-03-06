//============================================================================
// Name        : template.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <set>
#include <vector>
#include <string.h> // for memset in CF judge.
using namespace std;
#define _CRT_SECURE_NO_DEPRECATE // suppress some compilation warning messages (for VC++ users)
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
// To simplify repetitions/loops, Note: define your loop style and stick with it!
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define forn(i,n) \
for (int i =0; i<(n); i++)
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000 // 2 billion
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); // useful to clear array of integers

bool comp(ii a, ii b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second > b.second;
}

void solve() {
  int n, m;
  cin >> n >> m;
  long long gal = m;
  int c[n];
  bool valid = true;
  forn(i, n) {
    int x; cin >> x;
    c[i] = x;
  }
  int i = 0;
  while (gal > 0 && i < n) {
    if (c[i] > 0) gal += m - 1;
    else gal -= 1;
    i += 1;
  }
  if (i != n) {
    valid = false;
  }

  if (valid) {
    int dp[m + 1][n + 1];
    memset(dp, MEMSET_INF, sizeof dp);
    dp[0][0] = 0;

    forn(i, m + 1) {
      REP(j, 1, n) {

        dp[i][j] = dp[i][j - 1];
        if (c[j - 1] > 0) {

          dp[i][j] = min(dp[i][j], dp[i - 1][j] + c[j - 1]);
        }
      }
    }
    cout << dp[m][n] << " \n";
  } else {
    cout << -1 << " \n";
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 0;
  cin >> tc;
  int ct = 1;
  while (tc--) {
    cout << "Case #" << ct << ": ";
    ct++;
    solve();
  }
  return 0;
}