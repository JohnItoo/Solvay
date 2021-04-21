// Problem: C2. k-LCM (hard version)
// Contest: Codeforces - Codeforces Round #708 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1497/C2
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
    int tc; cin >> tc;
    while(tc--) {
    	int n, k; cin >> n >> k;
    	int mx = n/2;
    	vi mults;
    	mults.pb(1);
    	int curr = mx;
    	REP(i, 2, mx) {
    		if(curr % i == 0) {
    			mults.pb(i);
    		}
    		while(curr % i == 0) {
    			curr /= i;
    		}
    	}
       sort(mults.rbegin(), mults.rend());
       map<int, int> res;
       
       forn(i, mults.size()) {
       	if(mults[i] == 1) {
       		res[1] = k;
       		continue;
       	}
       	  if(n - mults[i] >= k-1 && n > 0) {
       	  	int ct = (n-k)/(mults[i] - 1);
 
       	  	n-= (mults[i] * ct);
       	  	k-=ct;
       	  	res[mults[i]] = ct;
       	  }
       }
       for(auto xx : res) {
       	int fq =xx.second;
       	int val = xx.first;
       	forn(k, fq) {
       		cout << val << " ";
       	}
       }
       cout << endl;
    }
    return 0;
}
