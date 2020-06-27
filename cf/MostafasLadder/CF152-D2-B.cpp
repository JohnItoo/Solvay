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
	ll n, m; cin >> n >> m;
	ll xc, yc; cin >> xc >> yc;
	int k; cin >> k;
	ll steps;
	forn(i, k) {
		ll x, y;
		cin >> x >> y;
		ll xlef = -1; ll ylef = -1;
		if (x < 0) {
			xlef = xc / abs(x);
		} else if (x == 0) {
			xlef = 0;
		} else {
			xlef = (n - xc) / x;
		}

		if (y < 0) {
			ylef = yc / abs(y);
		} else if (y == 0) {
			ylef = 0;
		} else {
			ylef = (m - yc) / y;
		}
		ll currSteps;

		if (xlef == 0 || ylef == 0) {
			currSteps = max(xlef, ylef);
		} else {
			currSteps = min(xlef, ylef);
		}
		if (x < 0) {
			xc -= currSteps;
		} else {
			xc += currSteps;
		}
		if (y < 0) {
			yc -= currSteps;
		} else {
			yc += currSteps;
		}
		cout << xc  << " ; " << yc << endl;
		steps += currSteps;
	}
	cout << steps << endl;

	return 0;
}
