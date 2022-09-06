// Problem: G. Even-Odd XOR
// Contest: Codeforces - Codeforces Round #817 (Div. 4)
// URL: https://codeforces.com/contest/1722/problem/G
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

void checker(vi& res) {
		int odd = 0; int ev = 0;
	for(int i = 0; i < res.size(); i++) {
		if(i & 1) {
			odd ^= res[i];
			
		} else {
			ev ^= res[i];
		}
	}
	cout << odd << " " << ev << endl;
	
	if(odd == ev) {
		cout << "OK\n";
	} else {
		cout << "not\n";
	}
}
void solve() {
	int n;cin >> n;
	if(n == 3) {
		cout << 2 << " " << 1 << " " << 3 <<endl;
		return;
		
	}
	vi odd_places;
	REP(i, 1, (n/2)) {
		odd_places.pb(i+1);
	}

	vi ev_places;
	forn(i, odd_places.size()) {
		if(i< odd_places.size()-2) {
		  ev_places.pb((1<< 30) + odd_places[i]);
		} 
		if(i == odd_places.size()-2) {
			if(odd_places.size() & 1) {
				ev_places.pb((1<< 30) + (1 << 29) + odd_places[i]);
			} else {
				ev_places.pb((1<< 30) + odd_places[i]);
			}
		}
		if( i == odd_places.size()-1) {
			if(odd_places.size() & 1) {
				ev_places.pb((1 << 29) + odd_places[i]);
			} else {
				ev_places.pb((1<< 30 )+ odd_places[i]);
			}
		}
	}
	vi res;
	if(n&1) {res.pb(0);};
	
	for(int i = 0; i < odd_places.size(); i++) {
		res.pb(odd_places[i]);
		res.pb(ev_places[i]);
	}
	for(auto it : res) {
		cout << it << " ";
	}
	cout << endl;
	//checker(res);

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
