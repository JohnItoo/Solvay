// Problem: A. Balance the Bits
// Contest: Codeforces - Codeforces Round #712 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1503/A
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0;
    int b = 0;
    int i = 0;
    string u = "", d = "";
    int small = 0;
    while (a > -1 && b > -1 && i < n) {
      if (s[i] == '1') {
        if (b > 0 && a > 0) {
          u.pb(')');
          d.pb(')');
          a--;
          b--;
        } else {
          u.pb('(');
          d.pb('(');
          a++;
          b++;
        }
      } else {
        if (a > b) {
          a--;
          b++;
          u.pb(')');
          d.pb('(');
        } else {
          a++;
          b--;
          u.pb('(');
          d.pb(')');
        }
        small = min(small, min(a, b));
      }
      i++;
    }

    if (i == n && a == 0 && b == 0 && small >= 0) {
      cout << "YES\n";
      cout << u << "\n" << d << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}
