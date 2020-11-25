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
	int n, m; cin >> n >> m;
	vi a(n + 1);
	REP(i, 1, n) cin >> a[i];
	vector<vector<int> > tree(n + 1, vector<int>());
	forn(i, n - 1) {
		int x , y;
		cin >> x >> y;
		tree[x].pb(y);
		tree[y].pb(x);
	}

	//dfs;

	stack<ii> st;
	st.push(mp(1, a[1]));
	map<int, int> visited;
	visited[1] = 1;
	int ans = 0;

	while (!st.empty()) {
		ii tp = st.top(); st.pop();
			if (visited.find(tp.first) != visited.end()) continue;
			visited[tp.first] = 1;
			cout << tp.first << "\n";
			if (tree[tp.first].size() == 1 && tp.second + a[tp.second] <= m) {
			ans++;
			continue;
		}
		for (int child : tree[tp.first]) {
			int second = a[child] == 1 ?  tp.second + 1 : 0;
			if(second <= m) st.push(mp(child, second));
		}
	}
	cout << ans << endl;


	return 0;
}
