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
		ll p, f; cin >> p >> f;
		ll cs, cw; cin >> cs >> cw;
		ll s, w; cin >> s >> w;
		ll eve = (cs * s) + (cw * w);


		ll ans = 0;
		if (p > eve || f > eve) {
			ans = cs + cw;
		} else {
			ll mxcar = max(p, f) / (s + w);
			ll took = min(mxcar, min(cs, cw));
			ll actual = took * (s + w);
			cs -= took;
			cw -= took;
			ans += took;
			if (p > f) {
				p -= actual;
				if (p > s && cs > 0) {
					p -= s;
					ans += 1;
					cs--;
				}
				if ( p > w && cw > 0) {
					p -= w;
					ans += 1;
					cw--;
				}

				ll mn = f / (s + w);
				ll mntook = min(mn, min(cs, cw));
				ll rem = mntook * (s + w);
				cs -= mntook;
				cw -= mntook;

				if (f > s && cs > 0) {
					f -= s;
					ans += 1;
					cs--;
				}

				if (f > w && cw > 0) {
					f -= w;
					ans += 1;
					cw--;
				}

			} else {
				f -= actual;
				if (f > s && cs > 0) {
					f -= s;
					ans += 1;
					cs--;
				}
				if ( f > w && cw > 0) {
					f -= w;
					ans += 1;
					cw--;
				}

				ll mn = p / (s + w);
				ll mntook = min(mn, min(cs, cw));
				ll rem = mntook * (s + w);
				cs -= mntook;
				cw -= mntook;

				if (p > s && cs > 0) {
					p -= s;
					ans += 1;
					cs--;
				}

				if (p > w && cw > 0) {
					p -= w;
					ans += 1;
					cw--;
				}
			}


		}




		cout << ans << "\n";
	}

	return 0;
}

