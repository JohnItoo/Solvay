// Problem: B. Scenes From a Memory
// Contest: Codeforces - Codeforces Round #741 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1562/B
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
    bool found = false;
    vector<int> mp(10, 0);
    int two = -1, five = -1;
    forn(i, n) {
      int here = s[i] - '0';
      mp[here]++;
      if (i > 0 && s[i] == '2') {
        two = i;
      }
      if (i > 0 && s[i] == '5') {
        five = i;
      }
    }
    int len = 0;
    int val = 0;
    if (mp[1] > 0) {
      len = 1;
      val = 1;
    } else if (mp[4] > 0) {
      len = 1;
      val = 4;
    } else if (mp[6] > 0) {
      len = 1;
      val = 6;
    } else if (mp[8] > 0) {
      len = 1;
      val = 8;
    } else if (mp[9] > 0) {
      len = 1;
      val = 9;
    }

    if (len <= 0) {
      if (two > 0) {
        len = 2;
        val = s[0] - '0';
        val *= 10;
        val += 2;
      } else if (five > 0) {
        len = 2;
        val = s[0] - '0';
        val *= 10;
        val += 5;
      } else if (mp[7] >= 2) {
        len = 2;
        val = 77;
      } else if (mp[2] >= 2) {
        len = 2;
        val = 22;
      } else if (mp[3] >= 2) {
        len = 2;
        val = 33;
      } else if (mp[5] >= 2) {
        len = 2;
        val = 55;
      } else {
        if (mp[2] > 0 && mp[7] > 0) {
          len = 2;
          val = 27;

        } else {
          len = 2;
          val = 57;
        }
      }
    }

    cout << len << "\n" << val << "\n";
  }

  return 0;
}
