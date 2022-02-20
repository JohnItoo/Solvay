// Problem: E - Knapsack 2
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//============================================================================
// Name        : BXK
// Author      : Template
// Version     :
// Copyright   : Who was here
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <bits/stdc++.h>
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
void solve() {
	// WORKS
 int n,wi; cin >> n >> wi;
 vector<pair<ll, ll>> prs(n);
 forn(i, n) {
 	ll x, y; cin >> x >> y;
 	prs[i] = {x, y};
 }
 int inf = 1e9 + 5;
 vector<ll> dp(1e6, inf);
 dp[0] = 0;
 //dp[val] is the minimum weight sum that can be used to get value val. There should be the using the first i elements state but we dropped it since we can go from left to right anyway
 for(auto& [w, v] : prs) {
 	for(int val = 1e5 + 4; val >= 0;  val --) {
 		if(dp[val] != inf) {
 			dp[val + v] = min(dp[val + v], dp[val] + w);
 		//	cout << val << " " << v << endl;
 			
 		}
 	}
 }
 //return;
 for(int val = 1e5; val >= 0; val--) {
 	if(dp[val] <=  wi) {
 		cout << val <<endl;
     	break;
 	}
 }
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
int tc = 1;
//cin >> tc;
int count = 1;
while(tc--) {

 //cout << "Case #" << count << ": "; //CODEJAM/KICKSTART
 count++;
 solve();
}
return 0;
}
