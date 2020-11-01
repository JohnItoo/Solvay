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
	int tc; cin >> tc;
	while (tc--) {
		int n, t;
		cin >> n >> t;
		vector<int> a(n);
		forn(i, n) {
			cin >> a[i];
		}
		vi res(n);
		if (t & 1) {
			forn(i, n) {
				if (a[i] & 1) {
					res[i] = 0;
				} else {
					res[i] = 1;
				}
			}
		} else {
			int lastval = 0;
			int last = 2;
			int lim = (n / 2) * 2;
			map<int, int> ones;
			map<int, int> zeros;
			forn(i, lim) {
				if ((a[i] & 1)) {
					if (last % 2 == 0) {
						res[i] = lastval;
					} else {
						lastval = (lastval == 0) ? 1 : 0;
						res[i] = lastval;
					}
				} else {
					if (last % 2 == 0) {
						lastval = (lastval == 0) ? 1 : 0;
						res[i] = lastval;
					} else {
						res[i] = lastval;
					}
				}
				last = a[i];
				if (lastval == 1) {
					ones[a[i]]++;
				} else {
					zeros[a[i]]++;
				}
			}
			if (n & 1) {
				int nd = t - a[n - 1];
				if (ones.find(nd) == ones.end()) {
					res[n - 1] = 1;
				} else {
					res[n - 1] = 0;
				}
			}
		}

		forn(i, n) cout << res[i] << " ";
		cout << "\n";


	}
	return 0;
}
