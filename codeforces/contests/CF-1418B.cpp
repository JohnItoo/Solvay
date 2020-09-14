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
	int tc;
	cin >> tc;
	while (tc--) {
		int n; cin >> n;
		vi a(n);
		vi l(n);
		vi p(n, -1);

		forn(i, n) cin >> a[i];
		forn(i, n) cin >> l[i];

		int lef = 0;
		vi pos; vi neg;
		forn(i, n) {
			if (l[i]) {
				p[i] = a[i];
				lef = i;
			} else {
				if (a[i] >= 0) pos.pb(a[i]);
				else neg.pb(a[i]);
			}
		}
		sort(pos.rbegin(), pos.rend());
		sort(neg.begin(), neg.end());

		int ip = 0;
		int mv = lef;

		while (mv >= 0 && ip < pos.size()) {
			if (l[mv] || p[mv] != -1) {
				mv--;
				continue;
			}

			p[mv] = pos[ip];
			mv--; ip++;
		}

		mv = lef;


		while (mv < n && ip < pos.size()) {
			if (p[mv] != -1  || l[mv]) {
				mv++;
				continue;
			}
			p[mv++] = pos[ip++];
		}

		int id = 0;
		forn(i, n) {
			if (l[i] || p[i] != -1) {
				cout << p[i] << " ";
				continue;
			}
			if (id < neg.size()) {
				p[i] = neg[id++];

			}
			cout << p[i] << " ";
		}
		cout << "\n";


	}
	return 0;
}
