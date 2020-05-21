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
	// to_string(int)

string trUpp(string s) {
	
  	transform(s.begin(), s.end(), s.begin(), ::toupper);
 return "";
}

int main() {
	
	ll n; cin >> n;
	ll u[n]; ll v[n];

	REP(i,1,n) {
		ll x ; cin >> x;
		u[i-1] = x;
		if(i == 1) v[i-1] = x;
		else v[i-1] = v[i-2] + x;
	}
	int m ; cin >> m;
	sort(u, u+n);

	ll vee[n];

	for(int i = 0; i < n; i++) {
		if(i==0) vee[i] = u[i];
		else vee[i] = vee[i-1] + u[i];
	}

	while(m--) {
		ll type , l,r; cin >> type >> l >> r;
		ll ans = 0;
		if(type == 1) {
           if(l == 1) ans = v[r-1];
           else ans = v[r-1] - v[l-2];
		} else {
          if(l == 1) ans = vee[r-1];
          else ans = vee[r-1] - vee[l-2];
		}
		cout << ans << endl;
	}

return 0;
}
