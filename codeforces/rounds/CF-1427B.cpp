// Problem: B. Chess Cheater
// Contest: Codeforces - Codeforces Global Round 11
// URL: https://codeforces.com/contest/1427/problem/B
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
bool comp(ii a, ii b) {
  // if((a.y - a.x) == (b.y - b.x)) return  a.y < b.y;
  // return(a.y - a.x) <  (b.y - b.x);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool in = false;
    int left = -1, right = -1;
    vii segs;
    forn(i, n) {
      if (!in && i > 0 && s[i] == 'L' && s[i - 1] == 'W') {
        left = i;
        in = true;
      } else if (in && s[i] == 'W') {
        right = i - 1;
        segs.pb(mp(left, right));
        in = false;
      }
    }
    if (in) {
      segs.pb(mp(left, n - 1));
    }
    // sort(segs.begin(), segs.end(), comp);
    int bod = n - 1;

    forn(i, segs.size()) {
      int l = segs[i].x, r = segs[i].y;
      if (k < r - l + 1) {
        continue;
      }
      while (k > 0 && l <= r) {
        s[l] = 'W';
        l++;
        k--;
      }
      if (k == 0) break;
    }

    int beg = 0, end = n - 1;
    if (s[beg] == 'L') {
      while (beg <= n - 1 && s[beg] == 'L') beg++;

      if (beg <= n - 1) {
        beg -= 1;
        while (beg >= 0 && k > 0) {
          s[beg] = 'W';
          beg--;
          k--;
        }
      }
    }

    if (s[end] == 'L') {
      while (end >= 0 && s[end] == 'L') end--;
      if (end >= 0) {
        end++;
        while (end < n && k > 0) {
          s[end] = 'W';
          end++;
          k--;
        }
      }
    }

    REP(i, 0, n - 1) {
      if (s[i] == 'L' && k > 0) {
        s[i] = 'W';
        k--;
      }
    }
    if (k > 0 && s[0] == 'L') {
      s[0] = 'W';
      k--;
    }

    in = false;
    int ans = 0;
    int i = 0;
    // cout << s << " : " << k << endl;
    while (i < n) {
      if (!in && s[i] == 'W') {
        ans++;
        in = true;
      } else if (s[i] == 'W') {
        ans += 2;
      } else if (in && s[i] == 'L') {
        in = false;
      }
      i++;
    }
    cout << ans << endl;
  }
  return 0;
}
