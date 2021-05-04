// Problem: Append Sort
// Contest: Google Coding Competitions - Round 1A 2021 - Code Jam 2021
// URL:
// https://codingcompetitions.withgoogle.com/codejam/round/000000000043585d/00000000007549e5
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
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
    vector<string> a(n);
    forn(i, n) cin >> a[i];
    int ans = 0;
    REP(i, 1, n - 1) {
      string x = a[i - 1], y = a[i];
      //	cout <<x << " " <<y << endl;
      int appd = -1;
      while (x.length() > y.length()) {
        if (appd == -1) {
          appd = y.length();
        }
        y.pb('0');
        ans++;
        appd = true;
      }
      if (y.length() == x.length()) {
        int l = x.length();
        int q = 0;
        while (q < l && x[q] == y[q]) q++;

        if (q == l) {
          if (appd == -1) {
            ans++;
            y.pb('0');
          } else {
            if (x[q - 1] == '9') {
              ans++;
              y.pb('0');
            } else {
              y[q - 1] = x[q - 1] + 1;
            }
          }
        } else if (x[q] > y[q]) {
          if (appd == -1) {
            ans++;
            y.pb('0');
          } else {
            if (q < appd) {
              ans++;
              y.pb('0');
            } else {  // q >= appd;
              if (x[q] == '9') {
                ans++;
                y.pb('0');
              } else {
                y[q] = x[q] + 1;
              }
            }
          }
        }
      }
      a[i] = y;
      //	cout << y << endl;
    }
    cout << ans << endl;
  }
  return 0;
}
