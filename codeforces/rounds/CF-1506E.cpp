// Problem: E. Restoring the Permutation
// Contest: Codeforces - Codeforces Round #710 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1506/E
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
    	set<int> fst, scd;
    	forn(i,n) {
    		cin >> a[i];
    		fst.insert(i+1);
    		scd.insert(i+1);
    	}
    	vi mn(n); vi mx(n);
    	mx[0] = mn[0] = a[0];
    	
    	
    	
    	REP(i, 0, n-1) {
    	   if(i == 0 || a[i] != a[i-1] ) {
    	   	mx[i] = mn[i] = a[i];
    	
    	   	fst.erase(a[i]);
    	   	scd.erase(a[i]);
    	   } else {
    	    auto ft = fst.lower_bound(a[i]);
    	    --ft;
    	    mx[i] = *ft;
    	    fst.erase(ft);
    	    
    	    auto st = scd.begin();
    	    mn[i] = *st;
    	    scd.erase(st);
    	   }
    	}
    	forn(i, n) {
    		cout << mn[i] << " ";
    	}
    	cout << endl;
    	forn(i, n) {
    		cout << mx[i] << " ";
    	}
    	cout << endl;
    	
    }
    return 0;
}
