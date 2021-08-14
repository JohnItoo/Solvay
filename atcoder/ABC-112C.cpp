// Problem: C - Pyramid
// Contest: AtCoder - AtCoder Beginner Contest 112
// URL: https://atcoder.jp/contests/abc112/tasks/abc112_c
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
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
    int n; cin >> n;
    vector<vector<int> > vals(n, vector<int>(3));
    int idx = -1;
    forn(i, n) {
    	cin >> vals[i][0] >> vals[i][1] >> vals[i][2];
    	if(vals[i][2] > 0) idx = i;
    }
    bool vld = true;
    REP(i, 0, 100) {
    	REP(j, 0, 100) {
    		
    		vi ans = {-1, -1, -1};
    		int H = vals[idx][2] + abs(i - vals[idx][0]) + abs(j - vals[idx][1]);
    		vld = true;
    		
    		forn(k, n) {
    			if(k == idx) continue;
    			int here = H- abs(i - vals[k][0]) - abs(j - vals[k][1]);
    			if(max(here, 0) != vals[k][2]) {
    				vld = false;
    				break;
    			}
    			
    			
    		}
    		if(vld ) {
    			cout << i << " " << j << " " << H << endl;
    			return 0;
    		}
    	}
    	
    }
    
    return 0;
}
