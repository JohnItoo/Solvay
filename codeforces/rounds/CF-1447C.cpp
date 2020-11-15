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
	int tc; cin >> tc;
	while (tc--) {
		ll n, mx; cin >> n >> mx;
		vector<ll> w(n);
		set<pair<ll, int> > st;
		bool fd = false;
		ll ceil = (mx + 1) / 2;
		ll dz = 0;

		forn(i, n) {
			cin >> w[i];
			st.insert(mp(w[i], i + 1));
			if (w[i] >= ceil && w[i] <= mx) {
				fd = true;
				dz = i + 1;
			}
		}
		if (fd) {
			cout << 1 << endl;
			cout << dz << endl;
			continue;
		}
		ll ans = 0;
		vi res;
		bool vld = false;
		for (auto xx : st) {

			if (xx.first + ans < ceil) {
				ans += xx.first;
				res.pb(xx.second);
			} else {
				if (xx.first + ans >= ceil && xx.first + ans <= mx) {
					res.pb(xx.second);
					vld = true;
					break;
				} else {
					break;
				}
			}
		}
		if (vld) {
			cout << res.size() << endl;
			forn(i, res.size()) cout << res[i] << " ";
			cout << endl;
		} else {
			cout << - 1 << endl;
		}
	}

	return 0;
}
