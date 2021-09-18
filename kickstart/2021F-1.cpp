// Problem: Trash Bins
// Contest: Google Coding Competitions - Round F 2021 - Kick Start 2021
// URL:
// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435bae/0000000000887c32
// Memory Limit: 1024 MB
// Time Limit: 20000 ms
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

    int n;
    cin >> n;
    string s;
    cin >> s;
    set<int> tr;
    forn(i, n) {
      if (s[i] == '1') tr.insert(i);
    }
    ll ans = 0;
    forn(i, n) {
      if (s[i] == '1') continue;
      auto it = tr.lower_bound(i);
      int left = INF, rt = INF;
      if (it == tr.end()) {
        --it;
        left = abs(*it - i);
      } else if (it == tr.begin()) {
        rt = abs(*it - i);
      } else {
        auto jt = it;
        --jt;
        left = abs(*jt - i);
        rt = abs(*it - i);
      }
      ans += (min(left, rt) * 1LL);
    }
    cout << ans << "\n";
  }
  return 0;
}
