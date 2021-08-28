// Problem: D - Various Sushi
// Contest: AtCoder - AtCoder Beginner Contest 116
// URL: https://atcoder.jp/contests/abc116/tasks/abc116_d
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
bool cmp(pair<ll, int> a, pair<ll, int> b) {
	return a.x > b.x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;
    
    vector<pair<ll, int> > vc(n);
    vi pres(n+5, 0);
    
    forn(i, n) {
    	ll d; int t; cin >> t >> d;
    	
    	vc[i] = {d,t};
    }
    
    sort(vc.begin(), vc.end(), cmp);
    
    int dn = 0;
    ll typ = 0;
    stack<ll> st;
    ll curr = 0;
    ll ans = 0;
    
    forn(i, n) {
    	if (dn < k) {
    		if(pres[vc[i].y] == 0) {
    			typ++;
    		} else {
    			st.push(vc[i].x);
    		}
    		dn++;
    		curr += vc[i].x;  
    		pres[vc[i].y] += 1;
    		ans = max(ans, curr + (typ*typ*1LL));
    		  		
    	} else {
    		if(st.empty()) break;
    		if(pres[vc[i].y] >= 1) continue;
    		pres[vc[i].y]++;
    	    ll top = st.top(); st.pop();
    	    
    		curr -= top;
    		typ++;
    		curr  += vc[i].x;
    		
    		ans = max(ans, curr+(typ*typ*1LL));
    	}
    }
    cout << ans << endl;
    return 0;
}
