// Problem: C. Berpizza
// Contest: Codeforces - 2020-2021 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules)
// URL: https://codeforces.com/problemset/problem/1468/C
// Memory Limit: 512 MB
// Time Limit: 5000 ms
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

struct myComp {
	bool operator()(ii a, ii b) {
		if(a.first == b.first) return a.second > b.second;
		return a.first < b.first;
	}
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    priority_queue<pair<int,int>, vector<pair<int, int> >, myComp > pq;
    vector<int> pips;
    int j = 1;
    map<int, int> done;
    int ct = 1;
    REP(i, 1, q) {
    	int x; cin >> x;
    	if(x == 1) {
    		int y; cin >> y;
    		pq.push(mp(y, ct));
    		pips.pb(y);
    		ct++;
    	} else if(x == 2) {
    		while(j <= pips.size() && done.count(j)) j++;
    		if(j <= pips.size()) cout << j << " ";
    		done[j] = 1;
    	} else {
    		while(pq.size() > 0 && done.count(pq.top().y)) pq.pop();
    		cout << pq.top().y << " ";
    		done[pq.top().y]++;
    		pq.pop();
    		
    	}
    }
    
    return 0;
}
