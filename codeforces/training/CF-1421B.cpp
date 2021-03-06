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
int dir[4][2] = { { -1, 0}, {0, -1}, {1, 0}, {0, 1}};
map<ii, int> visited;
bool fd = false;

void dfs(string arr[], char val, ii pt, int n) {

	if (visited.find(pt) != visited.end()) return;
	visited[pt] = 1;
	if ((pt.first == 0 && pt.second == 1) || (pt.first == 1 && pt.second == 0)) {
	    if(arr[pt.first][pt.second] == val) {
	    	fd = true;

	    }
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nr = pt.first + dir[i][0];
		int nc = pt.second + dir[i][1];
		if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
			continue;
		}
		if (arr[nr][nc] != val) {
			continue;
		}
		dfs(arr, val, mp(nr, nc), n);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		string arr[n];
		forn(i, n) {
			cin >> arr[i];
		}
		fd = false;
		dfs(arr, arr[n-2][n-1], mp(n-2, n-1), n);
		vii a;
		if(fd) {
			fd = false;
			a.pb(mp(n-1, n));
		}

		dfs(arr, arr[n-1][n-2], mp(n-1, n-2), n);

		if(fd) {
			a.pb(mp(n, n-1));
		}
		
		cout << a.size() << "\n";
		for(ii el : a) {
			cout << el.first << " " << el.second << "\n";
		}
		
	}
	return 0;
}
