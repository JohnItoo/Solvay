// Problem: C. A-B Palindrome
// Contest: Codeforces - Codeforces Round #713 (Div. 3)
// URL: https://codeforces.com/contest/1512/problem/C
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
    int exa = a;
    int exb = b;
    string s;
    cin >> s;
    int n = s.length();
    int mid = (n + 1) / 2;
    bool vld = true;
    if (n == 1) {
      if ((a == 1 && b == 0 && s[0] == '0')) {
        cout << 0 << endl;
      } else if (b == 1 && a == 0 && s[0] == '1') {
        cout << 1 << endl;
      } else if (b + a == 1 && s[0] == '?') {
        int q = a == 0 ? 1 : 0;
        cout << q << endl;
      } else {
        cout << -1 << endl;
      }
      continue;
    }
    forn(i, n) {
      if (s[i] == '1')
        b--;
      else if (s[i] == '0')
        a--;
    }

    forn(i, mid) {
      if (s[i] != '?' && s[i] != s[n - i - 1] && s[n - i - 1] != '?') {
        vld = false;
        break;
      }
      if (s[i] != '?' && s[n - i - 1] == '?') {
        s[n - i - 1] = s[i];
        if (s[i] == '1')
          b--;
        else
          a--;
      }

      if (s[i] == '?' && s[n - i - 1] != '?') {
        s[i] = s[n - i - 1];
        if (s[i] == '1')
          b--;
        else
          a--;
      }
      if (a < 0 || b < 0) {
        vld = false;
        break;
      }
    }
    if (!vld) {
      cout << -1 << endl;
    } else {
      forn(i, mid) {
        if (s[i] == '?') {
          if (a > b) {
            s[i] = '0';
            s[n - i - 1] = '0';
            if (i == n - i - 1)
              a -= 1;
            else
              a -= 2;
          } else {
            s[i] = '1';
            s[n - i - 1] = '1';
            if (i == n - i - 1)
              b -= 1;
            else
              b -= 2;
          }
        }
      }
      int cta = 0, ctb = 0;
      forn(i, n) {
        if (s[i] != s[n - i - 1]) {
          vld = false;
          break;
        }
        if (s[i] == '0')
          cta++;
        else
          ctb++;
      }
      if (vld && a == 0 && b == 0 && cta == exa && ctb == exb) {
        cout << s << endl;
      } else {
        cout << -1 << endl;
      }
    }
  }
  return 0;
}
