//============================================================================
// Name        : template.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc; cin >> tc;
  while (tc--) {
    ll r, b, g, w;
    cin >> r >> b >> g >> w;


    ll mn = min(r, min(b, g));
    bool fd = false;

    if (w & 1) {
      if (r % 2 == 0 && b % 2 == 0 && g % 2 == 0) {
        cout << "Yes\n";
        fd = true;
      }
    } else {
      if ((r % 2 == 0 && b % 2 == 0) || (r % 2 == 0 && g % 2 == 0 )  || (b % 2 == 0 && g % 2 == 0)) {
        cout << "Yes\n";
        fd = true;
      }
    }
    if (mn >= 1) {
      r -= 1;
      b -= 1;
      g -= 1;
      w += (1 * 3);
    }



    if (!fd) {
      if (w & 1) {
        if (r % 2 == 0 && b % 2 == 0 && g % 2 == 0) cout << "Yes\n";
        else cout << "No\n";
      } else {
        if ((r & 1 && b & 1 ) || (g & 1 && r & 1) || (g & 1 && b & 1)) cout << "No\n";
        else cout << "Yes\n";
      }
    }

  }
  return 0;
}
