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

int b1() {
	vi a(n);
	forn(i, n) {
		cin >> a[i];
	}

	int mn = d;
	for (int i = 0; i + d <= n; i++) {
		int ct = 0;
		map<int, int> has;
		for (int j = i; j < i + d && ct < mn ; j++) {
			if (has.find(a[j]) == has.end()) {
				ct++;
			}
			has[a[j]]++;

		}
		mn = min(ct, mn);
	}
	cout << mn << "\n";
	return 0;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	while (tc--) {
		int n, k, d; cin >> n >> k >> d;
		vi a(n);

		forn(i, n) {
			cin >> a[i];
		}


		int mn = d;
		map<int, int> has;
		int ct = 0;


		for (int i = 0; i  < d; i++) {
			if (has.find(a[i]) == has.end()) {
				ct++;
			}
			has[a[i]]++;

		}
		int ans = ct;

		for (int i = d; i < n; i++) {
			if (has[a[i - d]] == 1) {
				ct--;
				has.erase(a[i - d]);
			} else {
				has[a[i - d]]--;
			}

			if (has.find(a[i]) == has.end()) {
				ct++;
			}
			has[a[i]]++;
			ans = min(ct, ans);
		}
		cout << ans << "\n";



	}
	return 0;
}
