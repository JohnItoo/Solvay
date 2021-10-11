// Problem: E. Air Conditioners
// Contest: Codeforces - Codeforces Round #731 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1547/E
// Memory Limit: 512 MB
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

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <set>
#include <vector>
#include <string.h> // for memset in CF judge.
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
  // string s; cin >> s;
  // cout << s <<" s\n";
int n, k; cin >> n >> k;
  vector<ll> a, t;
  forn(i, k) {
  	ll x; cin >>x;
  	a.pb(x);
  	}
  forn(i, k) {
  	ll x; cin >> x;
  	t.pb(x);
  }

  ll mx = 1e10 -3;
   vector<ll> dpl(n+5, mx); vector<ll> dpr(n+5, mx);
  forn(i, k) {
  	dpl[a[i]] = t[i];
  	dpr[a[i]] = t[i];
  	//cout << dpl[a[i]] << " ";
  }
  REP(i, 1, n) {
  	dpl[i] = min(dpl[i], dpl[i-1] + 1);
  }
  
  for(int i = n; i >= 0; i--) {
  	dpr[i] = min(dpr[i+1] +1,dpr[i]);
  }
  
  REP(i, 1,n) {
  	cout << min(dpl[i], dpr[i]) << " ";
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
