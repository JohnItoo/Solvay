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

struct mv {
	ll c, s, f;

};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<mv> a(n - 1);
	forn(i, n - 1) {
		ll c, s, f ; cin >> c >>  s >> f;
		mv my = mv();
		my.c = c;
		my.s = s;
		my.f = f;
		a[i] = my;
	}
	vector<ll> res(n, 0);
	for (int i = 0; i < n - 1; i++) {
		ll current = a[i].c + a[i].s;
		for (int j = i + 1; j < n - 1; j++) {
			if (current <= a[j].s) {
				current = a[j].s + a[j].c;
			} else {
				ll g = (current - a[j].s + a[j].f - 1) / a[j].f;
				ll when = a[j].s + (g * a[j].f);
				current = when + a[j].c;
			}
		}
		res[i] = current;
	}

	forn(i, n) cout << res[i] << endl;

	return 0;
}
