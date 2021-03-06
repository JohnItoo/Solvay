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
	int tc;
	cin >> tc;
	while (tc--) {
		int n, x, y; cin >> n >> x >> y;
		if (n == 2) {
			cout << x << " " << y << "\n";
			continue;
		}
		vector<int> ans;
		int diff = y - x;
		for (int i = n - 1; i >= 0; i--) {
			if (i != 0 && diff % i != 0) continue;

			//mid
			vector<int> curr;
			int terv = 0;
			if (i != 0 ) terv = diff / i;
			if (terv != 0) {
				int pres = x;
				while (pres <= y) {
					curr.pb(pres);
					pres += terv;
				}

			} else {
				curr.pb(x);
				curr.pb(y);
			}
			int dis = x;
			terv = !terv ? y - x : terv;
			while (curr.size() <  n &&  dis - terv > 0) {
				dis -= terv;
				curr.pb(dis);
			}

			dis = y;

			while (curr.size() < n) {
				dis += terv;
				curr.pb(dis);
			}

			if (ans.size() == 0) {
				ans = curr;
			} else {
				int xy = *max_element(curr.begin(), curr.end());
				int xz = *max_element(ans.begin(), ans.end());
				// cout << xy << " ";
				// cout << xz << "\n";
				if (xy < xz) {
					ans = curr;
				}
			}
		}
		// sort(ans.begin(), ans.end());

		for (int xx : ans) {
			cout << xx << " ";
		}
		cout << "\n";
	}
	return 0;
}
