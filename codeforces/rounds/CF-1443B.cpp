// Problem: B. Saving the City
// Contest: Codeforces - Codeforces Round #681 (Div. 2, based on VK Cup
// 2019-2020 - Final) URL: https://codeforces.com/problemset/problem/1443/B
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
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int sn = s.length();
    int beg = 0;
    int end = sn - 1;
    while (beg < sn && s[beg] == '0') beg++;
    while (end > -1 && s[beg] == '0') end--;
    string nw = s.substr(beg, end - beg + 1);
    int i = 0, j = 0;
    ll ans = 0;
    vii prs;
    while (i < nw.length()) {
      int j = i;
      while (j < nw.length() && nw[j] == '1') j++;
      prs.pb(mp(i, j - 1));
      while (j < nw.length() && nw[j] == '0') j++;
      i = j;
    }
    int n = prs.size();
    int act = 1;
    int place = 0;
    if (n == 1) {
      cout << a << endl;
      continue;
    }
    int segs = prs.size();
    forn(i, n - 1) {
      int dist = prs[i + 1].x - prs[i].y;
      dist -= 1;
      if (dist * b < a) {
        ans += (dist * b);
        segs--;
      }
    }
    ans += (segs * a);
    cout << ans << endl;
  }
  return 0;
}