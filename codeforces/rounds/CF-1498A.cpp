// Problem: A. GCD Sum
// Contest: Codeforces - CodeCraft-21 and Codeforces Round #711 (Div. 2)
// URL: https://codeforces.com/contest/1498/problem/A
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
// ll gcd(ll a, ll b) {
	// if(b == 0) return a;
	// return gcd(b, a/b);
// }
ll sm (ll div) {;
    	ll sum = 0;
    	while(div) {
    	  sum += div % 10;
    	  div /= 10;
    	}
    	return sum;
}
ll gcd (ll a, ll b) {
	if(a==0) return b;
	return gcd(b%a, a);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
    	ll n; cin >> n;
    	
    	while(gcd(n, sm(n)) <= 1) {
    		n++;
    	}
    	cout << n << endl;
    	
    }
    return 0;
}
