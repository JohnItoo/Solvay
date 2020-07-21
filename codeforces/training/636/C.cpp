//============================================================================
// Name        : template.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <set>
#include <vector>
#include <string.h> // for memset in CF judge.
#include <cmath>
using namespace std;
#define _CRT_SECURE_NO_DEPRECATE // suppress some compilation warning messages (for VC++ users)
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
// To simplify repetitions/loops, Note: define your loop style and stick with it!
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define forn(i,n) \
for (int i =0; i<(n); i++)
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000 // 2 billion
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); // useful to clear array of integers

int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int n; cin >> n;
		int a[n];
		forn(i,n) cin >> a[i];
	 int dp[n+2][n+2];
	 memset(dp, INF, sizeof dp);
	 REP(i, 1,n) {
	 	dp[1][i] = a[i-1];
	 }
	 int maxd = 1;
	 REP(i, 0,  n-2) {
	 	if((a[i] < 0 && a[i+1] > 0) || (a[i] > 0 && a[i+1] < 0)) {
	 		dp[2][i+1] = a[i+1] + a[i];
	 		cout << i << " " << dp[2][i+1] << " ";
	 		maxd = 2;
	 	}
	 }
      
     for(int i = 3 ; i <= n; i++) {
     	bool p = false;
     	for(int j = 1; j+i-1<= n; j++) {
     		if(dp[i-1][j] == INF) continue;
     		// int x = i-1+j-1; int y = i-1+j-2; 
     		int x = j+i-2; int y = j+i-3;
     		if(x < 0 || x >=n || y <0 || y>=n) continue;
     		if((a[x] < 0 && a[y] < 0) || (a[x] > 0 && a[y] >0)) continue;
     		cout << "this is ax " << dp[i-1][j];
     		dp[i][j] = dp[i-1][j] + a[x];
     		p = true;
     	}
     	if(p) maxd = i;
     }



    int ans = -1;

    REP(i,1,n) {

    	if(dp[maxd][i] == INF) continue;
    	ans = max(dp[maxd][i], ans);
    }
     cout << endl;
     cout << ans << " " << maxd << endl;

	}
	return 0;
}
