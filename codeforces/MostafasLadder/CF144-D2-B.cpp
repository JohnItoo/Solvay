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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int xa, ya, xb, yb; cin >> xa >> ya >> xb >> yb;
	if (xa > xb) swap(xa, xb);

	vector<ii> seats;

	REP(x, xa, xb - 1) {
		if (x != xa) {
			seats.pb(mp(x, ya));
			seats.pb(mp(x, yb));
		} else {
			int mny = min(ya, yb);
			int mxy = max(ya, yb);
			REP(y, mny, mxy) {
				seats.pb(mp(x, y));
				seats.pb(mp(xb, y));
			}
		}
	}

	int n; cin >> n;

	vector<bool> htd(seats.size(), false);
	forn(i, n) {
		int x, y, r ; cin >> x  >> y >> r;
		forn(j , seats.size()) {
			if (htd[j]) continue;
			ii seat = seats[j];
			int x2 = seat.first;
			int y2 = seat.second;

			int xdiff = x - x2;
			int ydiff = y - y2;
			if ((xdiff * xdiff) + (ydiff * ydiff) <= (r * r)) {
				htd[j] = true;
			}
		}
	}

	int ans = 0;

	forn(i, htd.size()) {
		if (!htd[i]) ans++;
	}


	cout << ans << "\n";



	return 0;
}
