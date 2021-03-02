// Problem: D. Add to Neighbour and Remove
// Contest: Codeforces - Codeforces Round #690 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1462/D
// Memory Limit: 256 MB
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
    int tc; cin >> tc;
    while(tc--) {
    	int n; cin >> n;
    	vector<ll> a(n);
    	forn(i, n) cin >> a[i];
    	vector<ll> pref(n);
    	pref[0] = a[0];

    	map<ll, int> mp;
    	mp[a[0]] = 1;
    	REP(i, 1, n-1) {
    		 pref[i] = pref[i-1] + a[i];
    		 mp[pref[i]] = i+ 1;
    		 
    	}
    	int j = n-1;
    	int rt = n-2;
    	int i = rt;
    	int ans = n-1;
    	while(rt >= 0) {
    		ll diff = pref[j] - pref[i];
    		//cout << diff << "\n";
    		int mv = 0;

    		bool fd = false;
    		while(i >= 0) {
    			if(pref[j] - pref[i] > diff) break;
    			if(pref[j] - pref[i] != diff) {
    				i--;
    				continue;
    			}
    			mv += j - i - 1;
    			if(pref[i] == diff) {
    				fd = true;
    				mv += i;
    				break;
    			}
    			j = i;
    			i--;
    		}
    		if(fd && pref[j] - pref[i] == diff) ans = min(ans, mv);
    		j = n-1;
    		rt--;
    		i = rt;
    	}
    	cout << ans << endl;

    }
    return 0;
}
