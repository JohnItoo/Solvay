// Problem: B. The Modcrab
// Contest: Codeforces - Educational Codeforces Round 34 (Rated for Div. 2)
// URL: https://codeforces.com/contest/903/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    int h1,a1,c1; cin >> h1 >> a1 >> c1;
    int h2, a2; cin >> h2 >> a2;
    vector<string> res;
    while(h2 > 0) {
    	if(h1 > a2 || h2 - a1 <= 0) {
    		res.pb("STRIKE\n");
    		h2 -= a1;
    	} else {
    		res.pb("HEAL\n");
    		h1 += c1;
    	}
    	
    	if(h2 > 0) {
    		h1 -= a2;
    	}
    }
    cout << res.size() << "\n";
    forn(i, res.size()) cout << res[i];
    return 0;
}