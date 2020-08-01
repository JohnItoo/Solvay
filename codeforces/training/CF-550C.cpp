//============================================================================
// Name        : template.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
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
int n;
string ss;
string org;
int ans = -1;
map<string, int> mps;
void solve(int ct) {
	if (ans != -1) return;
	if (ct == n) {
		if (mps.find(ss) != mps.end()) {
			return;
		}

		ll x = -1;
		for (int i = 0; i < ss.length(); i++) {
			if (i == 0) {
				x = ss[i] - '0';
			} else {
				x = (x * 10) + ss[i] - '0';
			}
		}
		if (x % 8 == 0) {
			ans =  x;
		} else {
			mps[ss] = 1;
		}
		return;
	}

	solve(ct + 1);
	ss.pb(org[ct]);
	solve(ct + 1);
	ss.pop_back();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> org;
	n = org.length();
	solve(0);
	if (ans == -1) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		cout << ans << "\n";
	}


	return 0;
}
