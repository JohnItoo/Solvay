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
		int n, k, z;
		cin >> n >> k >> z;
		vi a(n);
		forn(i, n) cin >> a[i];
		int val = 0;
		ll sm = 0;
		vector<ll> pref(k + 2);

		forn(i, k) {
			if (a[i] + a[i + 1] > a[val] + a[val + 1]) {
				val = i;
			}
			pref[i + 1] = (ll) pref[i] + a[i];
		}
		pref[k + 1] = (ll) pref[k] + a[k];

		if (z == 0) {
			cout << pref[k + 1] << endl;

		} else {
			if (val + 1 + (z * 2) < k) {
				ll ans = pref[val + 2] + (a[val] * z) + (a[val + 1] * z);
				k -= (val + 1) + (z * 2);
				int mv = val + 2;
				while (mv < n && k > 0) {
					ans += (ll) a[mv++];

				}
				cout << ans << endl;
			} else {
				int rem = k - (val + 1);
				int moves = min(rem, z * 2);
				// cout << moves << " mv \n";
				int act = moves / 2;
				// cout << pref[val+2] << " pre\n";
				ll ans = pref[val + 2] + (a[val] * (moves - act)) + (a[val + 1] * act);
				cout << ans << endl;

			}
		}
		continue;
	}
	return 0;
}
