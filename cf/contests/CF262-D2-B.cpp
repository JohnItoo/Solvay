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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k; cin >> n >> k;
	vi a(n);
	vi positives;
	vi negatives;
	forn(i, n) {
		int x; cin >> x;
		if (x >= 0) positives.pb(x);
		else negatives.pb(x);
	}
	sort(positives.begin(), positives.end());
	sort(negatives.begin(), negatives.end());
	ll ans = 0;

	forn (i, negatives.size()) {
		if (k > 0) {
			ans += abs(negatives[i]);
			k--;
		} else {
			ans += negatives[i];
		}
	}
	if (k % 2 == 0) {
		forn(i , positives.size()) {
			ans += positives[i];
		}
	} else {
		if (positives.size() > 0) {
			ll currmax = ans;
			if (positives.size() > 0) {
				currmax += (positives[0] * -1);
			}
			REP(i, 1, positives.size() - 1) {
				currmax += positives[i];
			}
			ans = currmax;

		} else {
			ll secondMax = ans;
			secondMax -= (abs(negatives[negatives.size() - 1]));
			secondMax += negatives[negatives.size() - 1];
			ans = secondMax;
		}
	}
	cout << ans << endl;
	return 0;
}
