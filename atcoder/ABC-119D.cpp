// Problem: D - Lazy Faith
// Contest: AtCoder - AtCoder Beginner Contest 119
// URL: https://atcoder.jp/contests/abc119/tasks/abc119_d
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
set<ll> sh; set<ll> tem;

pair<ll, ll> nearestsh(ll x) {
	
	auto it = sh.lower_bound(x);
	
	ll ans = (1LL << 61);
	ll val;
	if(it != sh.end()) {
		ll calc = abs(x-*it);
		if(calc < ans) {
			val = *it;
			ans = calc;
		}
	}
	if(it != sh.begin()) {
		--it;
		ll calc = abs(x-*it);
		if(calc < ans) {
			val = *it;
			ans = calc;
		}
	}
	return {ans, val};
}

pair<ll, ll> nearestt(ll x) {

    auto it = tem.lower_bound(x);

	ll ans = (1LL << 61);
	ll val;
	
	if(it != tem.end()) {
	
		ll calc = abs(x-*it);
		if(calc < ans) {
			val = *it;
			ans = calc;
		}
	

	}
	if(it != tem.begin()) {
		--it;
		ll calc = abs(x-*it);
		if(calc < ans) {
			val = *it;
			ans = calc;
		}
	}
	
	
	

	
	return {ans, val};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,q;
    cin >> a >> b >> q;
    
    forn(i, a) {
    	ll x; cin >> x;
    	sh.insert(x);
    }
    forn(i, b) {
    	ll x; cin >> x;
    	tem.insert(x);
    }
    
    forn(i, q) {
    	ll x; cin >> x;
    	if(sh.find(x) != sh.end() && tem.find(x) != tem.end()) {
    		cout << 0 <<endl;
    	} else if(sh.find(x) != sh.end()) {
    		cout << nearestt(x).first << endl;
    	} else if(tem.find(x) != tem.end()) {
    		cout << nearestsh(x).first << endl;
    	} else {
    		pair<ll, ll> shnear = nearestsh(x);
    		pair<ll, ll> tnear = nearestt(x);
    		ll shrine = shnear.first;
    		ll temp =  tnear.first;
    		
    		ll res = min(shrine + nearestt(shnear.second).first, temp + nearestsh(tnear.second).first);
    		cout << res << endl;
    	}
    	
    	
    }
    return 0;
}
