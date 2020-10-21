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
int dir[6][2] = { { -1, 0}, {0, -1}, {1, 0}, {-1, -1}, {1,1}, {0, 1}};
map<ii, int> visited;
int res[2][2];


void dfs(string arr[], bool one, ii pt, int n) {

	if (visited.find(pt) != visited.end()) return;
	visited[pt] = 1;
	if ((pt.first == n - 2 && pt.second == n - 1) || (pt.first == n - 1 && pt.second == n - 2)) {
		if (one) {
			res[1][0] = pt.first + 1;
			res[1][1] = pt.second + 1;
		} else {
			res[0][0] = pt.first + 1;
			res[0][0] = pt.second + 1;

		}
		return;
	}

	for (int i = 0; i < 6; i++) {
		int nr = pt.first + dir[i][0];
		int nc = pt.second + dir[i][1];
		if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
			continue;
		}
		if ((one && arr[nr][nc] == '0') || (!one && arr[nr][nc] == '1')) {
			continue;
		}
		dfs(arr, one, mp(nr, nc), n);
	}
}

vector<vii> call(string arr[], int n) {

	vector<vii> ret;

	for (int i = 0; i < 2; i++) {
		memset(res, -1, sizeof res);
		visited.clear();
		dfs(arr, i, mp(0, 0), n);
		vii a;
		a.pb(mp(res[0][0], res[0][1]));
		a.pb(mp(res[1][0], res[1][1]));
		ret.pb(a);
	}

	return ret;

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
		vector<vii> dz = call(arr, n);
		bool zero = dz[0][0].first != -1 || dz[0][1].first != -1;
		bool one = dz[1][0].first != -1 || dz[1][1].first != -1;
		
		if(!zero && !one) {
			cout << 0 << "\n";
		} else {
			if(one && zero) {
				cout << 2 << "\n";
				cout << n<< " " << n-1 << "\n";
				cout << n-1 << " "<<  n << endl;
			} else {
				vii ff;
				if(one && (arr[n-1][n-2] == '1')) {
					ff.pb(mp(n-1, n-2));
				}
				if(one && (arr[n-2][n-1] == '1')) {
					ff.pb(mp(n-2, n-1));
				}

				if(zero && (arr[n-1][n-2] == '0')) {
					ff.pb(mp(n, n-1));
				}
				if(zero && (arr[n-2][n-1] == '0')) {
					ff.pb(mp(n-1, n));
				}
				cout << ff.size() << "\n";
				for(int k = 0; k < ff.size(); k++) {
					cout << ff[k].first << " " << ff[k].second << "\n";
				}

			}
		}
	}
	return 0;
}
