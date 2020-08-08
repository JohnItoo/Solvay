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
	int n;
	cin >> n;
	vi a(n);
	map<int, int> found;
	forn(i, n) {
		cin >> a[i];
		found[a[i]] = 1;
	}
	map<int, int> cant;
	map<int, ii> done;

	forn(i, n) {
		if (cant.find(a[i]) != cant.end()) continue;
		auto it = done.find(a[i]);

		if (it  == done.end()) {
			done[a[i]] = mp(0, i);
		} else {
			ii par = it->second;
			if (par.first == 0) {
				done[a[i]] = mp(i, i - par.second);
			} else {
				if (par.second != i - par.first) {
					cant[a[i]] = 1;
					done.erase(a[i]);
				} else {
					done[a[i]] = mp(i, par.second);
				}
			}
		}
	}

	vector<ii> res;
	for (auto it : done) {
		ii hlf = it.second;
		if (hlf.first == 0) {
			res.pb(mp(it.first, 0));
		} else {
			res.pb(mp(it.first, hlf.second));

		}
	}

	cout << res.size() << "\n";
	forn(i, res.size()) {
		ii par = res[i];
		cout << par.first << " " << par.second << "\n";
	}

	return 0;
}
