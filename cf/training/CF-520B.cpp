//============================================================================
// Name        : template.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string.h> // for memset in CF judge.
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
ll ans = 0;
void bfs(vector<ll> gp[], ll n, ll m) {
   queue<ll> q;
   map<ll, ll> visited;
   q.push(n);
   int i = 0;
   while(!q.empty()) {
   	 ll lst = q.front(); q.pop();
   	 if(visited.find(lst) != visited.end()) continue;
   	 visited[lst] =1;

   	 for( auto el : gp[lst]) {
        if(el == m) {
        	ans = i;
        	break;
        } else {
        	q.push(el);
        }
   	 }
   	 i++;
   }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m; cin >> n >> m;

	if (m <= n) {
		cout << n - m << endl;
		return 0;
	}

	vector<ll> gp[(2*m)+2];

	gp[1].pb(n * 2);
	gp[1].pb(n - 1);

	ll i = 2;
	REP(i, 1, n) {
			ll l = i * 2;
			ll r = i  - 1;
			if(l > 0) gp[i].pb(l);
			if(r > 0) gp[i].pb(r);
	}
	bfs(gp, n, m);

	cout << ans << endl;



	return 0;
}
