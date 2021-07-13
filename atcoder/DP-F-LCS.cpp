// Problem: F - LCS
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_f
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
    
    string s, t;
    cin >> s >> t;
    vector<vector<int> > dp(s.length()+1, vector<int>(t.length()+1, 0));
    
    for(int i =1; i <= s.length(); i++) {
    	
    	for(int j = 1; j <= t.length(); j++) {
    		
    		int up = dp[i-1][j];
    		int left = dp[i][j-1];
    		
    		dp[i][j] = max(up, left);
    		if(s[i-1] == t[j-1]) {
    			dp[i][j] = dp[i-1][j-1] + 1;
    		}
    	///	cout << dp[i][j] << " ";
    	}
    	//cout << endl;
    }
    int nxt = dp[s.length()][t.length()];
  
    string res;
    int i = s.length();
    int j = t.length();
    
    while(nxt) {
    	if(dp[i][j] == nxt && dp[i][j] > dp[i-1][j] && dp[i][j] > dp[i][j-1]) {
    		res.push_back(t[j-1]);
    		j--;
    		i--;
    		nxt--;
    	} else {
    		if(dp[i-1][j] > dp[i][j-1]) {
    			i--;
    		} else {
    			j--;
    		}
    	}
    	
    	
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}
