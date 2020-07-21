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
	// to_string(int)

string trUpp(string s) {
	
  	transform(s.begin(), s.end(), s.begin(), ::toupper);
 return "";
}
ll pf(ll n) {
	// ll vq[1000000000] = {0};
	map<ll, ll> mp;	
	ll sol = 0;
	for(ll i = 1; i*i <=n; i++) {
		if(mp.find(i) != mp.end()) continue;
		if(n % i == 0) {
			mp[i] = i; mp[n/i] = i;
           // vq[i] = 1; vq[n/i] = 1;
           if(i != n/i) sol += 2;
           else sol += 1;
		}
	} 
  
   return sol;
}
int main() {
 ll x = 0;
 vector<ll> vl;
 while(true) {
 	// cout << x << endl;
 	cin >> x;
 	 	if(x== 0) break;

    vl.pb(x);
 }
 forn(i, vl.size()) {
 	ll x = vl[i];

 	if(x== 0) break;

 	 // cout << "this is curr" << x;
 	 ll curr = pf(x);

 if(curr % 2 != 0) cout << "yes" << endl;
 else cout << "no" << endl;
 }
return 0;
}
