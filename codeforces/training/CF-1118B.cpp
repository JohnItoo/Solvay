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
	int n;
	cin >> n;
	ll od = 0,  ev = 0;
	vi a(n + 1);
	REP(i, 1, n) {
		cin >> a[i];
		if (i >= 2  && i & 1) ev += a[i];
		else if (i >= 2 && i % 2 == 0 ) od += a[i];
	}
	// cout << ev << " " << od << "\n";
	int i = 2;
	bool vld = od == ev ;
	ll ans = vld ? 1 : 0;
	while (i <= n) {

		while (i <= n && a[i - 1] == a[i]) {
			if (vld) ans++;
			i++;
		}
		vld = false;

		if (i <= n) {
			int diff = abs(a[i - 1] - a[i]);
			if ((i - 1) & 1) {

				if (a[i - 1] > a[i]) {
					od += diff;
				} else {
					od -= diff;
				}
			} else {
				if (a[i - 1] > a[i]) {
					ev += diff;
				} else {
					ev -= diff;
				}
			}

			if (ev == od) {
				ans++;
				vld = true;
			}
			i++;
		}


	}
	cout << ans << "\n";
	return 0;
}