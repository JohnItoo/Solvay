// Problem: C. Rings
// Contest: Codeforces - Codeforces Round #741 (Div. 2)
// URL: https://codeforces.com/contest/1562/problem/C
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
    int pos = n / 2;
    pos -= 1;
    int mk = -1;
    int bf = -1;

    REP(i, pos, n - 2) {
      string sb = s.substr(i, 2);
      if (sb == "10" || sb == "00") {
        mk = i;
        break;
      }
    }
    if (mk == -1) {  // no '10' or '00'
      int i = n - 1;
      while (i >= 0 && s[i] == '1')
        i--;  // this means concat of 1111.. from end to somewhere
              // before the halfway line

      if (i >= 0 && s[i] == '0') {
        i += 2;
        cout << i << " " << n - 1 << " " << i + 1 << " " << n
             << endl;  // '10' before halfway line
      } else {
        int le = (n / 2);
        int rs = le + 1;
        if (n & 1) {
          rs += 1;
        }
        cout << 1 << " " << n / 2 << " " << rs << " " << n
             << endl;  //'10' on halfway line
      }
    } else {  // there exists '10' or '00' to the right of the halfway line.
      cout << 1 << " " << mk + 2 << " " << 1 << " " << mk + 1 << endl;
    }
  }
  return 0;
}
