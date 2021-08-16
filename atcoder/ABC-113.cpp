// Problem: C - ID
// Contest: AtCoder - AtCoder Beginner Contest 113
// URL: https://atcoder.jp/contests/abc113/tasks/abc113_c
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
    int n, m; cin >> n >> m;
    vii ct, org;
    forn(i, m) {
    	int c, p; cin >> p >> c;
    	
    	ct.push_back({p, c});
    	org.push_back({p, c});
    	
    }
    sort(ct.begin(), ct.end());
    int prev = -1;
    int prec = 0;
    int i = 0;
    map<ii, string> mp;
    while(i < ct.size()) {
    	if(ct[i].x != prev) {
    		prev = ct[i].x;
    		prec = 1;
    		
    	} else {
    		prec++;
    		prev = ct[i].x;
    	}
    	string st = to_string(ct[i].x);
    	int sza = st.size();
       string zl = string(6- sza, '0');
      string stb = to_string(prec);
      int szb = stb.size();
    string zr = string(6-szb, '0');
     mp[ct[i]] = zl + st+ zr+ stb;

     i++;
    }
    
    for(auto xx : org) {
    	cout << mp[xx] << endl;
    }
    
    
    return 0;
}
