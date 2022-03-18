


// Problem: C. Increase Subarray Sums
// Contest: Codeforces - Educational Codeforces Round 123 (Rated for Div. 2)
// URL: https://c...content-available-to-author-only...s.com/problemset/problem/1644/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://c...content-available-to-author-only...r.org)
 
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
 int n,x; cin >> n >> x;
 vi a(n);
 forn(i, n) cin >> a[i];
 
 unordered_map<int, int> lenmx;
 
 int globalmax = 0;
 int pos = 1;
 lenmx[0] = 0;
 forn(i, n) {
 	int sm = 0;
 	if(a[i] < 0) {
 		pos = -1;
 	}
 	for(int j = i; j < n; j++) {
 		sm += a[j];
 		int len = (j - i) + 1;
 		if(lenmx.find(len) == lenmx.end()) {
 			lenmx[len] = sm;
 		} else {
 			lenmx[len] = max(lenmx[len], sm);
 		}
 		globalmax = max(globalmax, sm);
 	}
 }

 vi res;
 
 REP(len, 0, n) {
 	ll mx = 0;
 	REP(can, 0, n) {
 		  int newval = (x * min(can, len )) +  lenmx[can];
     mx = max(mx, newval * 1LL);
 	}
Ï
  cout << mx << " ";
  
  // max(maxsumofsubarrayoflen + increment, subarrayoflen is part of globalsum ? globalsum + x : globalsum)
  // so lets just remove arrays where everything is positive?
 }
 cout << endl;
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
