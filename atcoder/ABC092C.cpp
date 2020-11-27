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
	int n; cin >> n;
	vector<ll> a(n);
	forn(i, n) cin >> a[i];
	vector<ll> res(n);
	forn(i, n) {
		if (i == 0) {
			res[i] = abs(a[i]);
		} else {
			res[i] = res[i - 1] + abs(a[i] - a[i - 1]);
		}
	}

	forn(i, n) {
		if (i == 0) {
			ll ans = abs(a[1]) + (res[n - 1] - res[1]) + abs(a[n - 1]);
			cout << ans << endl;
		} else if (i == n - 1) {
			ll  ans = res[n - 2] + abs(a[n - 2]);
			cout << ans << endl;
		} else {
			ll ans = res[i - 1] + abs(a[i + 1] - a[i - 1])  + abs(a[n - 1]);

			if (i != n - 2) ans +=  (res[n - 1] - res[i + 1]);
			cout << ans << endl;
		}
	}

	return 0;
}
