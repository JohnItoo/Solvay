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
		int n, m; cin >> n >> m ;
		vector<vector<ll> > a(n, vector<ll>(m));
		forn(i, n) {
			forn(j, m) {
				cin >> a[i][j];
			}
		}
		ll ans = 0;
		forn(i, n / 2) {
			vector<ll> nums;
			forn(j, m) {
				nums.pb(a[i][j]);
				nums.pb(a[n - i - 1][j]);
			}
			sort(nums.begin(), nums.end());
			int sz = nums.size();
			ll med = nums[sz / 2];

			forn(s, sz) {
				ans += abs(med - nums[s]);
			}
		}
		// cout << ans << "\n";
		if (n & 1) {
			vi nums;
			int rw = (n / 2);
			forn(i, m) {
				nums.pb(a[rw][i]);
			}

			sort(nums.begin(), nums.end());
			int sz = nums.size();
			ll med = nums[sz / 2];

			forn(s, sz) {
				ans += abs(med - nums[s]);
			}

		}
		cout << ans << "\n";
	}
	return 0;
}