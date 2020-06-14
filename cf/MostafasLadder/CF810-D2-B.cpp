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
//WA
string trUpp(string s) {

	transform(s.begin(), s.end(), s.begin(), ::toupper);
	return "";
}

bool compare(ii a, ii b) {

	return min(a.first * 2, a.second) - min(a.first, a.second) > min(b.first * 2, b.second) - min(b.first, b.second);
}

int main() {
	ll n, f; cin >> n >> f;

	vector<pair<ll, ll> > days;

	forn(i, n) {
		ll a, b;
		cin >> a >> b;
		days.pb(mp(a, b));
	}
	sort(days.begin(), days.end(), compare);
	ll ans = 0;
	// cout << "konichiwa" << endl;
	forn(i, n) {
		// cout << days[i].first << " " << days[i].second << endl;
		if (f > 0 && days[i].first > 0) {
			ans += min(days[i].first * 2, days[i].second);
			f--;
			continue;
		}
		if (days[i].first > 0) {
			ans += min(days[i].first, days[i].second);

		}
	}
	cout << ans << endl;

	return 0;
}
