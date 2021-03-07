// Problem: E1. Close Tuples (easy version)
// Contest: Codeforces - Codeforces Round #690 (Div. 3)
// URL: https://codeforces.com/contest/1462/problem/E1
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
map<int, ll> factorial;
ll choose(int n) {
	if(n < 3) return 0;
	if(n == 3) return 1;
	ll curr = 1;
  if (factorial.count(n) == 0 || factorial.count(n-3) == 0) {
    for (int i = 1; i <= n; i++) {
      curr *= i;
      factorial[i] = curr;
    }
  }
  return factorial[n]/(6*factorial[n-3]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;

    while (tc--) {
      int n;
      cin >> n;
      map<int, int> freq;
      forn(i, n) {
        int x;
        cin >> x;
        freq[x]++;
      }
      ll ans = 0;
      for (auto el : freq) {
        int curr = el.x;
        int fq0 = el.y;
        int fq1 = freq.count(curr+1) != 0 ? freq[curr+1] : 0;
        int fq2 = freq.count(curr+2) !=  0 ? freq[curr+2] : 0;
        // cout << fq0 << " " << fq1 << " " << fq2 << endl;
        ans += choose(fq0);
        if(fq0 >= 1 && fq1 >= 1 && fq0 + fq1 >= 3){
        	ans += (fq0 + fq1 > 3) ? (fq0 * fq1) : 1;
        }
        if(fq2 >= 1 && fq0 >= 1 && fq0 + fq2 >= 3) {
        	ans +=  (fq0 + fq2 > 3) ? (fq0 * fq2) : 1;
        }
        if(fq1 >= 1 && fq0 >=1 && fq2 >= 1 && fq0 + fq1 + fq2 >= 3){
        	ans += (fq0 + fq1+ fq2 > 3) ? (fq0 *fq1 * fq2) : 1;
        }
      }
     cout << ans << "\n";
    }
  return 0;
}
