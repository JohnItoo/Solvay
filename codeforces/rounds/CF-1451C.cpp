// Problem: C. String Equality
// Contest: Codeforces - Codeforces Round #685 (Div. 2)
// URL: https://codeforces.com/contest/1451/problem/C
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

bool comp(pair<int, char> a, pair<int, char> b) {
  if (a.x == b.x) return a.y > b.y;
  return a.x > b.x;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    map<char, int> amap, bmap;
    vector<pair<int, char> > c;
    forn(i, n) { amap[a[i]]++; }
    forn(i, n) { bmap[b[i]]++; }

      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
    if (a == b) {
      cout << "Yes\n";
    } else {
    
      int i = 0;
      bool fd = true;
      while (i < n) {
        if (a[i] == b[i]) {
          i++;
          continue;
        } else {
          int ja = i, jb = i;
          bool left = true;
          REP(q, ja + 1, ja + m - 1) {
            if (a[q] != a[q - 1]) {
              left = false;
              break;
            }
          }
          bool rt = true;
          REP(q, ja + 1, ja + m - 1) {
            if (b[q] != b[q - 1]) {
              rt = false;
              break;
            }
          }
          if (left && rt && a[i] < b[i]) {
            i += m;
          } else {
            fd = false;
            break;
          }
        }
      }
      if (fd)
        cout << "Yes\n";
      else
        cout << "No\n";
    }
  }
  return 0;
}
