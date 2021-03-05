// Problem: B. Berland Crossword
// Contest: Codeforces - Educational Codeforces Round 105 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1494/problem/B
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
    	int n, u, r, d, l; cin >> n >> u >> r >> d >> l;
    	bool fd = true;
    	// if(n == 2) {
//     		
    	// }
    	// if(u == n && d == n) {
    		// if(l < 2 || r < 2) {
    			// fd = false;
    		// } else {
    			// fd = fd && true;
    		// }
    	// }
        // if(l == n && r == n) {
    		// if(u < 2 || d < 2) {
    			// fd = false;
    		// } else {
    			// fd = fd && true;
    		// }
    	// } 
    	// if(u == n || d == n) {
    		// if(l < 1 || r < 1) {
    			// fd = false;
    		// } else {
    			// fd = fd && true;
    		// }
    	// } 
    	 // if(l == n || r == n) {
    		// if(u < 1 || d < 1) {
    			// fd = false;
    		// } else {
    			// fd = fd && true;
    		// }
    	// } 
    		// if(fd) cout << "YES\n";
    	// else cout << "NO\n";
    	
    	// ll desh = (l == n) + (r == n);
    	// ll desv = (u == n) + (d== n);
    	// if(u < desh || d < desh || r < desv || l < desv) cout << "NO\n";
    	// else cout << "YES\n";
    	 fd = true;
    	int desu = u, desr = r, desd = d, desl = l;
    	
    	if(desu == n) {
    		desl--;
    		desr--;
    	} else if(desu == n-1 && desl > desr) {
    		desl--;
    	} else if(u == n-1) {
    		desr--;
    	}
    	if(desl + desr + n - 2 >= desd) {
    		fd = true;
    	} else {
    		fd = false;
    		
    	}
    	desu = u, desr = r, desd = d, desl = l;
    	
    	if(desl == n) {
    		desu--;
    		desd--;
    	} else if(desl == n-1 && desu > desd) {
    		desu--;
    	} else if(desl == n-1) {
    		desd--;
    	}
    	if(desu + desd + n - 2 >= desr) {
    		fd = fd & true;
    	} else {
    		fd = false;
    	}
    	if(fd) cout << "YES\n";
    	else cout << "NO\n";
    	
    
    }
    return 0;
}
