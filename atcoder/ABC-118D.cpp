// Problem: D - Match Matching
// Contest: AtCoder - AtCoder Beginner Contest 118
// URL: https://atcoder.jp/contests/abc118/tasks/abc118_d
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
int n, m; 
vi cst {0, 2,5,5,4,5,6,3,7,6};
vi a;

string comp(string curr, string val) {
	if(curr == "") return val;
	int lenc= curr.size();  int lenv = val.size();
	if(lenc > lenv) return curr;
	if(lenv > lenc) return val;
	int i = 0, j = 0;
	while(i < lenc &&  j < lenv) {
		if(curr[i] > val[j]) {
			return curr;
		} else if(val[j] > curr[i]) {
			return val;
		} else {
			i++;
			j++;
		}
	} 
	return curr;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

     cin >> n >> m;
     a.resize(m);
     
     forn(i, m) cin >> a[i];
     
     
     vector<string> dp(n+20, "");
     
     forn(i, m) {
     	dp[cst[a[i]]] = comp(dp[cst[a[i]]], to_string(a[i]));
     }
     
     REP(i, 1, n) {
     	forn(j, m) {
     		int cost = cst[a[j]];
     		if(i < cost) continue;
     		if(dp[i - cost] == "") continue;
     		string s = dp[i-cost];
     	    s.append(to_string(a[j]));
     		dp[i] = comp(dp[i], s);
     	}
     }
  
     cout << dp[n] << endl;
    
    return 0;
}
