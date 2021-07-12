// Problem: College Life 4
// Contest: CodeChef - March Challenge 2021 Division 3
// URL: https://www.codechef.com/MARCH21C/problems/COLGLF4
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
typedef unsigned long long int ll;
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
  for (int i = int(a); i <= int(b); i++)  // a to b, and variable i is loal!
  
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
ll checker(int n, int e, int h, int a, int b, int c) {
  ll mx = 1e18;
  REP(i, 0, n) {
    REP(j, 0, n) {
      //	REP(k, 0, n) {
      int k = n - i - j;
     
      if (k < 0 || i + j + k != n || (i * 2) + j > e || (k * 3) + j > h) continue;
      ll curr = (i * a) + (j * c) + (k * b);
      if (curr < mx) {
     //cout << j << " cakes : " << i << "  oms : " << k << " shakes\n";
        mx = curr;
        //	}
      }
    }
  }
  return mx;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, e, h, a, b, c;
    cin >> n >> e >> h >> a >> b >> c;
    
    ll mx = 1e18;
    ll ans = 0;
    int lim = min(n, min(e, h));
    REP(i, 0, lim) {
      int lef = e-i;
      int rig = h-i;
      int oms = lef/2;
      int shakes = rig / 3;
      if(a < b) {
      	oms = min(oms, n-i);
      	shakes = min(shakes, n-i-oms);
      } else {
      	shakes = min(shakes, n-i);
      	oms = min(oms, n-i -shakes);
      	
      }
      if(oms + shakes + i == n) {
      	ll val =  oms *a + shakes * b + i * c * 1LL;
      	mx = min(mx, val);
      }
      if(mx == 1e18) cout << -1;
      else cout << mx << endl;
    }
  }
 // cout << endl << endl << sumn;
  return 0;
}
