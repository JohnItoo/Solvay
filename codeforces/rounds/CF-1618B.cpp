// Problem: B. Missing Bigram
// Contest: Codeforces - Codeforces Round #760 (Div. 3)
// URL: https://codeforces.com/contest/1618/problem/B
// Memory Limit: 256 MB
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
 int n; cin >> n;
 string prev = "";
 string res;
 forn(i, n-2) {
 	string c; cin >> c;
 	if(i == 0) {
 		res.pb(c[0]);
 	} 
   if(i != 0) {
 		
 		if(prev[1] != c[0]) {
 		res.pb(prev[1]);
 		res.pb(c[0]);
 		}  else {
 			res.pb(c[0]);
 		}
 		
 		
 	}
 	if(i == n-3) {
 			res.pb(c[1]);
 	}
 	prev = c;
 	
 }
 if(res.size() != n) {
 	res.pb('a');
 }
 cout << res <<endl;
 
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
int tc = 1;
cin >> tc;
int count = 1;
while(tc--) {

 //cout << "Case #" << count << ": "; //CODEJAM/KICKSTART
 count++;
 solve();
}
return 0;
}
