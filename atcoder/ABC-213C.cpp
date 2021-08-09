// Problem: C - Reorder Cards
// Contest: AtCoder - AtCoder Beginner Contest 213
// URL: https://atcoder.jp/contests/abc213/tasks/abc213_c
// Memory Limit: 1024 MB
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h,w, n; cin >> h >> w >> n;
    set<ii> row;
    set<ii> col;
    vii cells;
    vii res(n);
    map<int, int> rmp, cmp;
    
    forn(i, n) {
    	int r, c; cin >> r >> c;
    	row.insert({r, i+1});
    	col.insert({c, i+1});
    	cells.pb({r,c});
    }
    
    int ct = 0;
    int prev = -1;
    for(auto it : row) {
    	int val = it.x;
    	if(val != prev) ct++;
    	prev = val;
    	rmp[it.y] = ct;
    }
    ct = 0;
    prev = -1;
    for(auto it: col) {
    	int val = it.x;
    	if(val != prev) ct++;
    	prev = val;
    	cmp[it.y] = ct;
    }
    
    REP(i, 1, n) {
    	cout << rmp[i] << " " << cmp[i] << endl;
    	
    }
    
    
    return 0;
}
