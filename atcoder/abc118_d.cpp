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
vi a;
vi cst {0,2,5,5,4,5,6,3,7,6};
string ans = "";

void comp(string curr) {
	if(ans == "") {
		ans = curr;
	} else {
		int a = curr.size(), b = ans.size();
		if(b > a) return;
		if(a > b) {
			ans = curr;
			return;
		}
		int i = 0, j = 0;
		while(i < a && j < b) {
			if(ans[i] > curr[j]) {
				return;
			} else if(ans[i] == curr[j]){
				i++; j++;
			} else {
				ans = curr;
				return;
			}
		}
		
	}
}

void bt(int n, string curr) {
	if(n <= 0) {
		comp(curr);
		return;
	}
	for(int i = 0; i < m; i++) {
		if(n < cst[a[i]]) continue;
		curr.append(to_string(a[i]));
		bt(n- cst[a[i]], curr);
		curr.pop_back();
	}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    a.resize(m);
    forn(i, m) {
    	cin >> a[i];
    }
    string curr = "";
    bt(n, curr);
    cout << ans << endl;
    
    
    return 0;
}
