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
	int tc;  cin >> tc; 
	
	while (tc--) {
		ll x, y; cin >> x >> y;
		if (x < y) swap(x, y);
		if (x % y != 0 || (x % y == 0 && (  x!= 1 && x %2 != 0 && y == 1))) {
		 cout << -1 << endl;
		} else {
			ll div = x/y;
			if(div == 1) cout << 0 << endl;
			else if(div % 2 != 0 ) {cout << -1 << endl;}
			else {
				ll ans = 0;
				while (x > y) {
					bool can = false;
					if (div >= 8 && div % 8 == 0) {
						x /= 8;
						can = true;
					} else if (div >= 4 && div % 4 == 0) {
						x /= 4;
						can = true;
					} else if (div >= 2 && div % 2 == 0) {
						x /= 2;
						can = true;
					}
					if (!can) { ans = -1; break;}
					ans++;

				}
				cout << ans << endl;

			}
		}
	}
	return 0;
}
