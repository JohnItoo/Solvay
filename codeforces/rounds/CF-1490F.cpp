// Problem: F. Equalize the Array
// Contest: Codeforces - Codeforces Round #702 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1490/F
// Memory Limit: 256 MB
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
    int tc; cin >> tc;
    while(tc--) {
    	int n; cin >> n;
    	vi a(n);
    	map<int, int> mpa;
    	forn(i, n) {
    		int x ; cin >> x;
    		mpa[x]++;
    	}
    	map<int, int> mpb;
    	for(auto it : mpa) {
    		int item = it.first;
    		int fq = it.second;
    		mpb[fq]++;
    	}
        vii pr;
        for(auto it: mpb) {
        	pr.pb(mp(it.first, it.second));
        }
        if(pr.size() == 1) {
        	cout << 0 << "\n";
        } else {
        	sort(pr.rbegin(), pr.rend());
        int best = 1e9+8;
           forn(i, pr.size()) {
           	int curr = 0;
           	 forn(j, pr.size()) {
           	 	if(pr[j].x >= pr[i].x) {
           	 		curr += ((pr[j].x - pr[i].x) * pr[j].y);
           	 	} else {
           	 		curr += (pr[j].x * pr[j].y);
           	 	}
           	 }
           	 best = min(best, curr);
           }
           cout << best << endl;
        }
    }
    return 0;
}
