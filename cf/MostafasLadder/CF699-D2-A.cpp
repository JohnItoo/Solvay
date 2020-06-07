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

int main() {
	ll n; cin >> n;
	string mv; cin >> mv;
	vector<ll> lef; vector<ll> rt;
	ll arr[n];
	memset(arr, 0, sizeof arr);

	forn(i, n) cin >> arr[i];
	forn(i, n) {
		if (mv[i] == 'L') lef.pb(arr[i]);
		else rt.pb(arr[i]);
	}
	if (lef.size() == 0 || rt.size() == 0) {
		cout << -1 << endl;
		return 0;
	}
	int i = 0; int j = 0;
	ll sm = INF;
	while (i < lef.size() && j < rt.size()) {
		ll curr = (lef[i] - rt[j]) / 2;
		if (curr > 0) {
			sm = min(sm, curr);
		}

		if (lef[i] > rt[j]) j++;
		else i++;
	}
	if (i < lef.size()) {
		while (i < lef.size()) {
			ll curr = (lef[i] - rt[j - 1]) / 2;
			if (curr > 0) {
				sm = min(sm, curr);
			}
			i++;
		}
	} else {
		while ( j < rt.size()) {
			ll curr = (lef[i - 1] - rt[j]) / 2;
			if (curr > 0) {
				sm = min(sm, curr);
			}
			j++;
		}
	}

	if (sm == INF) sm = -1;
	cout << sm << endl;

	return 0;
}
