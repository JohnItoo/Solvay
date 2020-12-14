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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1, vector<int>());
	vector<int> c(n);
	forn(i, n) cin >> c[i];
	forn(i, m) {
		int x, y; cin >> x >> y;
		graph[x].pb(y);
		graph[y].pb(x);
	}
	map<int, set<int>> occ;
	for (int i = 1; i <= n; i++) {
		int col = c[i - 1];
		for (int edges : graph[i]) {
			if (c[edges - 1] == col) continue;
			occ[col].insert(c[edges - 1]);
		}
	}
	int ans = -1;
	int sz = -1;
	for (auto ij : occ) {
		int curr = (ij.second).size();
		if(ans == -1) {
			ans = ij.first;
			sz = curr;
			continue;
		}
		if (curr > sz) {
			ans = ij.first;
			sz = curr;
		}
	}
	cout << ans << endl;
	return 0;
}
