// Problem: A. ABC String
// Contest: Codeforces - Educational Codeforces Round 105 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1494/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor
// (https://cpeditor.org)//============================================================================
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
    string s;
    cin >> s;
    int n = s.length();
    if (s[0] == s[n - 1]) {
      cout << "NO\n";
    } else {
      int cl = 0;
      int i = 0;
      int seen = -1;
      bool corr = true;
      string one = "";
      forn(i, n) {
        if (s[i] == s[0])
          one.pb('(');
        else if (s[i] == s[n - 1])
          one.pb(')');
        else
          one.pb('(');
      }

      string two = "";
      forn(i, n) {
        if (s[i] == s[0])
          two.pb('(');
        else if (s[i] == s[n - 1])
          two.pb(')');
        else
          two.pb(')');
      }

      int op = 0;
      bool fd = true;
      forn(i, one.size()) {
        if (one[i] == '(')
          op++;
        else
          op--;
        if (op < 0) {
          fd = false;
          break;
        }
      }
      fd = fd && (op == 0);
      int ox = 0;
      bool gd = true;
      forn(i, one.size()) {
        if (two[i] == '(')
          ox++;
        else
          ox--;
        if (ox < 0) {
          gd = false;
          break;
        }
      }
      gd = gd && (ox == 0);

      if (fd || gd)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
