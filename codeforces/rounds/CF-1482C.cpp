// Problem: C. Basic Diplomacy
// Contest: Codeforces - Технокубок 2021 - Финал
// URL: https://codeforces.com/problemset/problem/1482/C
// Memory Limit: 512 MB
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
    	int n, m; cin >> n >> m;
    	vector<set<int> > avs;
    	forn(i, m) {
    		int ct; cin >> ct;
    		set<int> st;
    		forn(j, ct) {
    			int x; cin >> x; st.insert(x);
    		}
    		avs.pb(st);

    	}
    	int y = (m+1) / 2;
    	vector<int> counts(n+1, 0);
    	vector<int> order(m, 0);
    	bool inv = false;
    	int last = 1;
    	forn(i, m) {
    		if(last > n) last = 1;
    		int pick = last;
    		set<int> hr = avs[i];

    		
    		if(hr.size() == 1) {
    			pick = *hr.begin();

    		} else {
    			if(hr.lower_bound(last) == hr.end()) {
    				last = 1;
    			}
    			pick = *(hr.lower_bound(last));
    		
    		}

    		
    		counts[pick]++;
    		order[i] = pick;
    		if(counts[pick] > y) {inv = true; break;}
    		last = pick + 1;
    	}

    	if(inv) cout << "NO";
    	else{
    		cout << "YES\n";
    		forn(i, m) cout << order[i] << " ";
    		cout << endl;
    	}
    }
    return 0;
}
