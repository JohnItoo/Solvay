// Problem: C. Not Assigning
// Contest: Codeforces - Codeforces Round #766 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1627/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//============================================================================
// Name        : BXK
// Author      : Template
// Version     :
// Copyright   : Who was here
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

int val = 2;
void dfs(vi& res, vector<vector<ii>>& gp, int root, unordered_map<int, int>& visit) {
    visit[root] = 1;
	for(auto& [u, id] : gp[root]) {
		if(visit.find(u) != visit.end()) continue;

		visit[u] = 1;
		res[id] = val;
		// cout << u << " " << val <<endl;
		if(val == 2) {
			val = 3;
		} else {
			val = 2;
		}
	
		dfs(res, gp, u, visit);
	}
}
void solve() {
  int n; cin >> n;
  vector<vector<ii>> gp(1e5+5, vector<ii>());
  val = 2;
  REP(i, 1, n-1) {
  	int u, v; cin >> u >> v;
  	gp[u].pb({v, i});
  	gp[v].pb({u, i});
  	if(gp[u].size() > 2 || gp[v].size() > 2) {
  		cout << -1 << endl;
  		return;
  	}
  }
  int root = 0;
  REP(i, 1, n) {
  	 if(gp[i].size() == 1) {
  	 	root = i;
  	 	break;
  	 }
  }
  //cout << root << " root\n";
  
 vector<int> res(n+5, -19);
 unordered_map<int, int> visit;
 dfs(res, gp, root, visit);
 
 REP(i, 1, n-1) {
 	cout << res[i] << " ";
 }
 cout << endl;
  
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
int tc = 1;
cin >> tc;
int count = 1;
while(tc--) {

 //cout << "Case #" << count << ": "; //CODEJAM/KICKSTART
 count++;
 solve();
}
return 0;
}
