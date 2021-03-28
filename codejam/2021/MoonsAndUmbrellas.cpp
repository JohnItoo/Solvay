// Problem: Moons and umbrellas
// Contest: Google Coding Competitions - Qualification Round 2021 - Code Jam
// 2021 URL:
// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1145
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
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
int greedy() {  // For partial points
  int tc;
  cin >> tc;
  int count = 1;
  while (tc--) {
    cout << "Case #" << count << ": ";
    count++;
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    int n = s.length();
    int onground = 0;
    REP(i, 1, n - 1) {
      if (s[i] == 'C' && s[i - 1] == 'J') {
        onground += y;
      } else if (s[i] == 'J' && s[i - 1] == 'C') {
        onground += x;
      }
    }
    int cjs = 0, jcs = 0;
    char last = '.';
    bool in = false;
    REP(i, 0, n - 2) {
      if (s[i] != '?' && s[i + 1] == '?') {
        in = true;
        last = s[i];
      } else if (in && s[i] == '?' && s[i + 1] != '?') {
        in = false;
        string dz = "";
        dz.pb(last);
        dz.pb(s[i + 1]);
        if (dz == "CJ")
          cjs++;
        else if (dz == "JC")
          jcs++;
      }
    }
    int ans = cjs * x + jcs * y + onground;
    cout << ans << endl;
  }
  return 0;
}

int main() {  // For full points
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  int count = 1;
  while (tc--) {
    cout << "Case #" << count << ": ";
    count++;
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int> > dp(n + 1, vector<int>(2, 1e9 + 8));
    dp[0][0] = 0;
    dp[0][1] = 0;
    if (s[0] == '?') {
      dp[1][0] = 0;
      dp[1][1] = 0;
    } else if (s[0] == 'C') {
      dp[1][0] = 0;
    } else {
      dp[1][1] = 0;
    }
    REP(i, 2, n) {
      char ch = s[i - 1];

      if (ch == '?') {
        dp[i][0] = min(dp[i][0], dp[i - 1][0]);      // CC
        dp[i][0] = min(dp[i][0], dp[i - 1][1] + y);  // JC
        dp[i][1] = min(dp[i][1], dp[i - 1][0] + x);  // CJ
        dp[i][1] = min(dp[i][1], dp[i - 1][1]);      // JJ
      } else if (ch == 'C') {                        // options //JC // CC
        dp[i][0] = min(dp[i][0], dp[i - 1][1] + y);  // JC
        dp[i][0] = min(dp[i][0], dp[i - 1][0]);      // CC
      } else {                                       // CJ JJ
        dp[i][1] = min(dp[i][1], dp[i - 1][0] + x);  // CJ
        dp[i][1] = min(dp[i][1], dp[i - 1][1]);      // JJ
      }
    }
    cout << min(dp[n][1], dp[n][0]) << endl;
  }

  return 0;
}
