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

//returns the minimum stoptime


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<pair<int, ii> > a(n);
	forn(i, n) {
		char c; cin >> c;
		int x, y;	cin >> x >> y;
		a[i] = mp( c == 'N' ? 1 : 0 , mp(x, y));
	}
	vector<vector<int> > res(n, vector<int>());
	vi mins(n);

	vector<vector<int> > act(n, vector<int>(2));
	vector<vector<int> > post(n, vector<int>(2));
	vii mps(n);
	map<ii, int> places;

	forn(i, n) {
		if (a[i].first) {
			act[i][0] = 0;
			act[i][1] = 1;
		} else {
			act[i][0] = 1;
			act[i][1] = 0;
		}
		post[i][0] = (a[i].second).first;
		post[i][1] = (a[i].second).second;
		places[mp(post[i][0], post[i][1])] = 1;
	}
	int sim = 10000;

	vector<int> result(n, INF);
	for (int i = 1; i <= sim ; i++) {
		for (int id = 0; id < n;  id++) {
			if (result[id] != INF) continue;
			post[id][0] += act[id][0];
			post[id][1] += act[id][1];
			ii currpair = mp(post[id][0], post[id][1]);
			if (places.find(currpair) == places.end()) {
				places[currpair] = i;
			} else if (places[currpair] != i) {
				result[id] = i;
			}
		}
	}
	forn(i, n) {
		if (result[i] == INF) {
			cout << "Infinity\n";
		} else {
			cout << result[i] << endl;
		}
	}


	return 0;
}
