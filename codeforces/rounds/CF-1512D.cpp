// Problem: D. Corrupted Array
// Contest: Codeforces - Codeforces Round #713 (Div. 3)
// URL: https://codeforces.com/contest/1512/problem/D
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

    	vector<ll> a(n+2);
    	forn(i, n+2) cin >> a[i];
    	sort(a.begin(), a.end());
    	ll sm = 0;
    	forn(i, n) {
    		sm += a[i];
    	}
    	int exa = -1 , exb = -1;
  
    	if(sm ==  a[n+1] || sm == a[n]) {
    		exa = n;
    		exb = n+1;
    	} else {
    		forn(i, n) {
    			if(sm - a[i] + a[n] == a[n+1]) {
    				exa = i;
    				exb = n+1;
    				break;
    			} 
    			if(sm - a[i] + a[n+1] == a[n]) {
    				exa = i;
    				exb = n;
    				break;
    			}
    		}
    
    	}
    		if(exa == -1) {
    			cout << exa;
    		} else {
    			
    			forn(i, n+2) {
    				if(i == exa || i == exb) continue;
    				cout << a[i] << " ";
    			}
    		
    		}
    	cout << endl;
    }
    return 0;
}
