// Problem: B. Move and Turn
// Contest: Codeforces - Codeforces Round #691 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1459/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
map<int, vi> mpvi;
int ct = 0;
map<ii, int> has;
int lim;

void backtrack(int x, int y, int i, int s) {
	if(s == lim+1) {
		ii dz = mp(min(abs(x), abs(y)), max(abs(x), abs(y)) );
		if(has.count(dz)) return;
		has[dz] = 1;
		cout << dz.x << " : " << dz.y << "\n";
		
		ct++;
		return;
	}
	vi curr = mpvi[i];
	for(int mv : curr) {
		backtrack(x + dir[mv][0], y +  dir[mv][1], mv, s+1);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> lim;
    mpvi[0].pb(2);
    mpvi[0].pb(3);
    mpvi[1] = mpvi[0];
    mpvi[2].pb(0);
    mpvi[2].pb(1);
    mpvi[3] = mpvi[2];
    forn(i, 4) {
    	backtrack(0, 0, i, 1);
    }
    //brute force
    cout  << ct << "\n";

    return 0;
}
