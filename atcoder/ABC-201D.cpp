// Problem: D - Game in Momotetsu World
// Contest: AtCoder - Mynavi Programming Contest 2021（AtCoder Beginner Contest 201）
// URL: https://atcoder.jp/contests/abc201/tasks/abc201_d
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int w, h; cin >> h  >> w;
    vector<string> g(h);
    string tot = "";
    forn(i , h) {
     cin >> g[i];
      tot += g[i];
     
    }
    if(w == 1 && h == 1) {
    	cout << "Draw\n";
    	return 0;
    }
    int ap = 0, an = 0, tp = 0, tn = 0;
    map<int, int> cellstep;
    map<int, int> sumstep;
    
    
    stack<pair<int, int> > st;
    st.push(mp((0*w) + 2, 1));
    st.push(mp((1*w) + 1, 1));
    map<int, int> vis;
    while(!st.empty()) {
    	ii tp = st.top(); st.pop();
    	if(vis.count(tp.x)) continue;
    	vis[tp.x] = 1;
    	cellstep[tp.y]++;
    	if(tot[tp.x - 1] == '-') {
    		sumstep[tp.y]--;
    	} else {
    		sumstep[tp.y]++;
    	}
    	if(tp.x + w <= ((h-1) * w ) + w) {
    		st.push(mp(tp.x+w, tp.y+1));
    	}
    	if(tp.x % w != 0) {
    		st.push(mp(tp.x+1, tp.y+1));
    	}
    }
    for(auto step: cellstep) {
    	if(sumstep.count(step.x)) {
    		if(step.y == abs(sumstep[step.x])) {
    			if(step.x & 1) {
    				if(sumstep[step.x] < 0) {
    					tn++;
    				} else {
    					tp++;
    				}
    			} else {
    				if(sumstep[step.x] < 0) {
    					an++;
    				} else {
    					ap++;
    				}
    			} 
    		}
    	}
    }
  //  cout << ap << " " << tp << " " << an << " " << tn << endl;
    int sma = ap - an; int smt = tp - tn;
    if(ap < tp || sma < smt) {
    	cout << "Takahashi\n";
    } else if(ap > tp || sma > smt) {
    	cout << "Aoki\n";
    } else {
    	cout << "Draw\n";
    }
    
    return 0;
}
