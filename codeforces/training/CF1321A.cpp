//============================================================================
// Name        : template.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <set>
#include <vector>
#include <string.h> // for memset in CF judge.
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
  int n; cin >> n;
  int a[n]; int b[n];
  forn(i, n) cin >> a[i];
  forn(i, n) cin >> b[i];
  int tota = 0; int totb = 0; int exa = 0; int exb = 0;
  forn(i,n) {
  	if(a[i] == b[i] && a[i] == 1) {
  		tota += 1; totb += 1;
  	}
   if(a[i] == 1 && b[i] == 0) {
  		exa += 1;
  		tota += 1;
  	}
  	if(a[i] == 0 && b[i] == 1) {
  		exb += 1;
  		totb += 1;
  	}
  } 
  int ans = -1; 
  // cout << exa << exb << endl; cout <<  tota << totb << endl;

  if(exa != 0 || exb != 0) {
  	if(tota > totb) ans = 1;
  	if(tota == totb) ans = 2;
  	if(tota < totb && exa > 0) {
  		int nn = (totb + 1) - tota;
  		int sol = (nn + exa - 1)/exa;
   		ans = sol+1;
  	}
  } 
  cout << ans << endl;
return 0;
}
