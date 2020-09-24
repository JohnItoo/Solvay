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
		vi a;
		vi b;
		int n; cin >> n;
		vector<pair<int, int> > vp;
		forn(i, n) {
			int x; cin >> x;
			a.pb(x);
			vp.pb(mp(x, i));
		}
		sort(vp.rbegin(),  vp.rend());

		int comp = ((n * (n - 1)) / 2) - 1;
		int ans = 0;
		int i = n - 1;
		int vpi = 0;
		map<int, int> dn;


		while (i >= 0 && vpi + 1 < n) {
			ii curr = vp[vpi];
			while (vpi + 1 < n && curr.first >= a[i]) {
				// cout << vpi << endl;
				if (dn.find(i) != dn.end()) {
					vpi++;
					curr = vp[vpi];
					continue;
				}

				a.pb(curr.first);
				dn[curr.second] = 1;
				ans += abs(curr.second - i);
				vpi++;
				curr = vp[vpi];
			}
			while (i > 0 && dn.find(i) != dn.end()) {
				// cout << "here\n";
				i--;
			}
		}

		if (ans <= comp) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
