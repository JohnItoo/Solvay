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
// to_string(int)

string trUpp(string s) {

	transform(s.begin(), s.end(), s.begin(), ::toupper);
	return "";
}

int main() {
	int n, m;
	vector<vector<ii> > grp(101, vector<ii>());
	cin >> n >> m;
	set<int> colors;
	forn(i, m) {
		int a, b, c; cin >> a >> b >> c;
		grp[a].pb(mp(b, c));
		grp[b].pb(mp(a, c));
		colors.insert(c);
	}
	int q; cin >> q;
	forn(i, q) {
		int ans = 0;

		int u, v; cin >> u >> v;
		for (int color : colors) {
			stack<int> stck;
			bool isvalid = false;
			for (ii curr : grp[u]) {
				if (curr.second == color) {
					stck.push(curr.first);
				}
			}
			vector<bool> visited(101, false);

			while (!stck.empty()) {
				int pt = stck.top(); stck.pop();
				if (visited[pt]) continue;
				visited[pt] = true;
				if (pt == v) {
					isvalid = true;
					break;
				}
				for (auto vertex : grp[pt]) {
					if (vertex.second == color) {
						stck.push(vertex.first);
					}
				}
			}

			if (isvalid) ans++;
		}
		cout << ans << "\n";

	}

	return 0;
}
