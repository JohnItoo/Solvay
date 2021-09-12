// Problem: C. MAX-MEX Cut
// Contest: Codeforces - Codeforces Global Round 16
// URL: https://codeforces.com/contest/1566/problem/C
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
    string a, b;
    cin >> a >> b;
    bool zero = false, one = false;

    int i = 0;
    int ans = 0;
    int last = 0;
    while (i < n) {
      int j = i;
      last = j;
      bool z = false;
      bool o = false;
      int purez = 0;
      bool lsz = false, lso = false;
      while (j < n && (!z || !o)) {
        z |= a[j] == '0';
        o |= a[j] == '1';
        z |= b[j] == '0';
        o |= b[j] == '1';
        if (b[j] == '0' && a[j] == '0') purez++;
        lsz = a[j] == '0' || b[j] == '0';

        lso = a[j] == '1' || b[j] == '1';
        j++;
      }
      if (z && o) {
        if (purez >= 1) {
          if (!(lsz && lso)) {
            purez--;
          }
          // cout << purez << "purez\n";
          ans += max(purez + 2, 2);
        } else {
          ans += 2;
        }

      } else if (z) {
        ans += j - last;
      }

      i = j;
      zero |= z;
      one |= o;
    }
    int res = ans;
    if (zero && one && res < 2) res = 2;
    cout << res << endl;
  }
  return 0;
}
