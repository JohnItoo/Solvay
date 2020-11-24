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
		ll n; cin >> n;

		ll prm = 1;
		ll times = 1;
		for (ll i = 2; i * i <= n; i++) {
			if (n % i != 0) {
				continue;
			}
			ll curr = 0;

			ll target = n;
            // cout << target % i << " " << i <<endl;
			while ((target % i) == 0 && target % (i * i) == 0) {
				target /= i;
				curr++;

			}
			if (curr + 1 > times) {
				times = curr + 1;
				prm = i;
			}
		}
		if(prm == 1) {
			cout << 1 << endl;
			cout << n << endl;
		} else {
			vector<ll> anns;
			while(n % prm == 0 && n% (prm*prm) == 0) {
				anns.pb(prm);
				n/=prm;
			}
			anns.pb(n);
			cout << anns.size() << endl;
			forn(i, anns.size()) cout << anns[i] << " ";
			
			cout << endl;
		}
	}


	return 0;
}
