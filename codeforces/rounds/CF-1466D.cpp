// Problem: D. 13th Labour of Heracles
// Contest: Codeforces - Good Bye 2020
// URL: https://codeforces.com/problemset/problem/1466/D
// Memory Limit: 256 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//============================================================================
// Name        : template.cpp
// Author      :   $%U%$   
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
    	int n; cin >> n;
    	vi a(n+1, 0);
    	REP(i, 1, n) cin >> a[i];
    	vi deg(n+1);
    	forn(i, n-1) {
    		int u, v; cin >> u >> v;
    		deg[u]++;
    		deg[v]++;
    	}
    	priority_queue<pair<int, int> > q;
    	REP(i, 1, n) {
    		if(deg[i] -1 > 0) {
    			q.push(mp(a[i], deg[i]-1));
    		}		
    	}
    	
    	ll sm = accumulate(a.begin(), a.end(), 0LL);
    	cout << sm << " ";
    	
    	REP(i, 1, n-2) {
    		ii curr = q.top(); q.pop();
    		sm += (ll) curr.x;
    		if(curr.y -1 > 0) {
    			q.push(mp(curr.x, curr.y-1));
    		}
    		cout << sm << " ";
    	}
    	cout << "\n";
    }
    return 0;
}
