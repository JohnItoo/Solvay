// Problem: D - String Formation
// Contest: AtCoder - AtCoder Beginner Contest 158
// URL: https://atcoder.jp/contests/abc158/tasks/abc158_d
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
    string s; cin >> s;
    int n; cin >> n;
    int vld = 0;
    string left = "";
    string right = "";
    forn(i, n) {
    	int t; cin >> t;
    	if(t == 1) {
    		vld = vld == 1 ? 0 : 1;
    	} else {
    		int wh; char c; 
    		cin >> wh >> c;
    		if(wh == 1) {
    			if(vld == 1) right.push_back(c);
    			else left.push_back(c);
    		} else {
    			if(vld == 1) left.push_back(c);
    			else right.push_back(c);
    		}
    		
    	}
    }
   
    if(vld == 1) {
    	reverse(right.begin(), right.end());
    	reverse(s.begin(), s.end());
    	cout << right + s + left << endl;
    } else {
    	 reverse(left.begin(), left.end());
    	cout << left + s + right << endl;
    }
    return 0;
}
