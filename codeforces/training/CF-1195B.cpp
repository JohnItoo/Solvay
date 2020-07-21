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
#include <cmath>
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

// MY OWN VERSION WITH SQUARE ROOT AND THE QUADRATIC EQUATION
int sq() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, k; cin >> n >> k;
	ll a = 1;
	ll b = -(n + 1 + n + 2);
	ll c = (n * (n + 1)) - (2 * k);
	ll rt = (b * b) - (4 * a * c);
	ll mis = sqrt(rt);
	ll ans1 = (-(b) + mis) / (2 * a);
	ll ans2 = (-(b) - mis) / (2 * a);

	ll us = n - ans1;
	ll ans = 0;
	if (ans1 <= n) {
		ans = ans1;
	} else {
		ans = ans2;
	}
	cout << ans << "\n";
	return 0;
}

// EDITORIAL BINARY SEARCH.
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, k; cin >> n >> k;
	ll l = -1; ll r = n + 1;
	while (r > l + 1) {
		ll m = (l + r) / 2;
		ll curr = (((n - m) *  (n - m + 1)) / 2) - m;
		if (curr > k) { l = m;}
		else r = m;
	}
	cout << r << "\n";
}
