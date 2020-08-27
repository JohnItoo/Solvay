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
	vector<ii> lef; vector<ii> rig;
	while (n--) {
		int x , y;
		cin >> x >> y;
		if (x < 0) lef.pb(mp(x, y));
		else rig.pb(mp(x, y));
	}
	sort(lef.begin(), lef.end());
	sort(rig.begin(), rig.end());
	int i = 0; int j = 0;
	int sol = 0;
	int mn = min(lef.size(), rig.size());
	bool is = 0;
	if (lef.size() < rig.size()) is = 1;
	if (is && mn > 0) {
		forn(i , lef.size()) {
			sol += lef[i].second;
		}

		forn(i, rig.size()) {
			sol += rig[i].second;
		}
		sol += rig[mn].second;
	} else if (!is && mn > 0) {
		forn(i , rig.size()) {
			sol += rig[i].second;
		}

		forn(i, lef.size()) {
			sol += lef[i].second;
		}
		if (mn < rig.size()) {
			sol += rig[mn].second;

		}

	} else if (mn == 0) {
		if (is) {
			if (rig.size() >= 1)
				sol = rig[0].second;
		} else {
			if (lef.size() >= 1)
				sol = lef[0].second;
		}
	}
	cout << sol << "\n";
	return 0;
}
