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

ll gcd(ll a, ll b) {
	return (b == 0) ? a : gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll l, r; cin >> l >> r;

	for (ll i = l; i + 2 <= r; i++) {
		for (ll j = i + 1; j + 1 <= r; j++) {
			for (ll k = j + 1; k <= r; k++) {
				if (i == j || j == k || i == k) continue;
				ll first = gcd(i, j);
				ll sec = gcd(j, k);
				ll third = gcd(i, k);
				ll arr[3] = {first, sec, third};
				sort(arr, arr + 3);
				ll ans[3] = {i , j , k};
				sort(ans, ans+3);
				if (arr[0] == 1 && arr[1] == 1 && arr[2] != 1) {
					cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
					cout << first << " " << sec << " " << third << endl;
					return 0;
				}
			}
		}
	}
	cout << - 1 << endl;
	return 0;
}
