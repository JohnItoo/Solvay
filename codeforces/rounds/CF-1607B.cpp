// Problem: B. Odd Grasshopper
// Contest: Codeforces - Codeforces Round #753 (Div. 3)
// URL: https://codeforces.com/contest/1607/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
 ll x, n; cin >> x >> n;
 if(n == 0) {
 	cout << x << endl;
 	return;
 }
 ll beg = 0;
 if(x & 1) {
 	beg = 1;
 } else {
 	beg = -1;
 	
 }
 ll left = n-1;
 ll tms = left/4;
 ll nxt = (tms*4) + 2;
 ll jumps = (tms*4) + 1;
 int ct = 0;
 ll extra = 0LL;
 while(jumps < n) {
 	if(ct < 2) {
 		if(beg == 1) {
 			extra += (-nxt);
 		} else {
 			extra += nxt;
 		}
 	} else {
 		if(beg == 1) {
 			extra += nxt;
 		} else {
 			extra += (-nxt);
 		}
 	}
 	jumps++;
 	ct++;
 	nxt++;
 }
 ll ans = 0;
 if(beg == 1) {
 	ans = (tms*4) + beg + extra + x;
 } else{
 	ans = -(tms*4) + beg + extra + x;
 }
 cout << ans <<endl;
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
