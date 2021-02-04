//============================================================================
// Name        : template.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
#define _CRT_SECURE_NO_DEPRECATE  // suppress some compilation warning messages
                                  // (for VC++ users)
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
// To simplify repetitions/loops, Note: define your loop style and stick with
// it!
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define REP(i, a, b) \
    for (int i = int(a); i <= int(b); i++)  // a to b, and variable i is local!
#define forn(i, n) for (int i = 0; i < (n); i++)
#define TRvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000  // 2 billion
// If you need to recall how to use memset:
#define MEMSET_INF 127      // about 2B
#define MEMSET_HALF_INF 63  // about 1B
// memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path
// distances memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP
// memoization table memset(arr, 0, sizeof arr); // useful to clear array of
// integers
// to_string(int)

string trUpp(string s) {
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    return "";
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n + 3, vector<int>());
    forn(i, m) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
	map<int, int> vis;
	ll ans = 1;
	REP(i, 1, n) {
		if(!adj[i].size() || vis.count(i)) continue;
		stack<int> mv;
		mv.push(i);
		while(!mv.empty()) {
			int tp =mv.top();mv.pop();
			if(vis.count(tp)) continue;
			vis[tp] = 1;
			if(tp != i) ans*=2;
			for(int edg: adj[tp]) {
               mv.push(edg);
			}
		}
	}
	cout << ans << endl;

    return 0;
}
