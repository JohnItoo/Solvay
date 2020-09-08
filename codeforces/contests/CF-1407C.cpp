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
		int n; cin >> n;
		vi a(n + 1);
		REP(i, 1, n) {
			cin >> a[i];
		}
		if (n == 2) {
			int ons = 0; int zers = 0;
			REP(i, 1, n) {
				if (a[i] == 1) ons++;
				else zers++;
			}
			if (n == 2 ) {
				if (zers > 0) {
					cout << 1 << "\n";
					cout << 0 << "\n";
				} else {
					cout << 2 << "\n";
					cout << a[1] << " " << a[2] << "\n";
				}
			}
			continue;
		}
		vi res;
		int i = 1;
		while (i <= n && i + 2 <= n) {
			int ones = 0;
			int zs = 0;
			for (int j = i; j <= i + 2; j++) {
				if (a[j] == 1) ones++;
				else zs++;
			}
			int lst = 0;
			if (ones > zs) {
				res.pb(1); res.pb(1);
				lst = 1;
			} else {
				res.pb(0); res.pb(0);
			}

			if (lst == a[i + 2]) {
				i = i + 3;
			} else {
				i = i + 2;
			}
		}
		cout << res.size() << "\n";

		for (int dd : res) {
			cout << dd << " ";
		}
		cout << "\n";

	}
	return 0;
}
