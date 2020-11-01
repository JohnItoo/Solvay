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
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <tuple>
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


void solve() {
	int n, k, w;
	cin >> n >> k >> w;
	vector<ll> l(n);

	forn(i, k)  cin >> l[i];


	ll al, bl, cl, dl;
	cin >> al >> bl >> cl >> dl;

	vector<ll> h(n);
	forn(i, k) cin >> h[i];

	ll ah, bh, ch, dh;
	cin >> ah >> bh >> ch >> dh;


	REP( i , k , n - 1) {
		l[i] = ((al * l[i - 2] + bl * l[i - 1] + cl) % dl) + 1;
		h[i] = ((ah * h[i - 2] + bh * h[i - 1] + ch) % dh) + 1;
	}

	vector<tuple<ll, ll, ll, ll> > rooms(n);

	ll g = 1;

	forn(i, n) {
		tuple<ll, ll, ll , ll> tp = make_tuple(l[i], 0L, l[i] + w, h[i]);
		rooms[i] = tp;
	}

	vector<ll> per(n);
	int laststart = 0;
	int lastorg = 0;
	vector<int>overlaps(n, 0);
	overlaps[0] = 1;
	ll heightHere = h[0];

	forn(i, n) {


		ll p, q, r, s;
		tie(p, q, r, s) = rooms[i];

		bool overlap = true;

		if (i > 0) {
			ll plast, qlast, rlast, slast;
			tie(plast, qlast, rlast, slast) = rooms[laststart];
			if (rlast < p) {
				overlap = false;

				if (overlaps[i - 1] && get<0>(rooms[i])  < get<2>(rooms[i - 1]))  {
					//prev overlaps with 0 && curr overlaps prev;
					overlaps[i] = 1;
					heightHere = max(heightHere, h[i]);
				} else {
					laststart = i;
					heightHere = h[i];
				}
			} else {
				overlaps[i] = overlaps[i - 1];

				if (overlaps[i] || get<0>(rooms[i]) <= get<2>(rooms[laststart])) {
					heightHere = max(heightHere, h[i]);
				} else {
					heightHere = h[i];
				}

			}

		}
		ll width = r - l[laststart];

		ll currp = 2 * (heightHere + width);

		ll porg, qorg, rorg, sorg = 0;
		tie(porg, qorg, rorg, sorg) = rooms[0];
		if (rorg >= p) {
			lastorg = i;
			cout << "lastorgs\n";
		}
		if (!overlaps[i]) {
			per[i] = (per[lastorg] + currp);
		} else {
			per[i] = currp;
		}

	}

	forn(i, n) {
		g *= per[i];
		g %= 1000000007;

	}

	cout << g <<  "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc = 0;
	cin >> tc;
	int ct = 1;
	while (tc--) {
		cout << "Case #" << ct << ": ";
		ct++;
		solve();
	}
	return 0;
}

