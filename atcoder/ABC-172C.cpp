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
int n, m, k;
ll a[200005];
ll b[200005];
ll ans = 0;
ll dfs(int i, int j, ll mins, ll curr) {
	if (mins > k || (i >= n  && j >= m)) {
		ans = max(ans, curr);
		return curr;
	}
	return max( dfs(i + 1, j, mins + a[i], curr + 1), dfs(i, j + 1, mins + b[j], curr + 1));
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;

	forn(i, n) cin >> a[i];
	forn(i, m) cin >> b[i];

	ll tp = 0; ll bt = 0;
	ll tm = 0;
	ll ans = 0;
	while (tp < n && bt < m && tm < k) {
		bool wt = 0;
		if (a[tp] < b[bt]) {
			tm += a[tp];
			tp++;
		} else {

			tm += b[bt];
			bt++;
			wt = 1;
		}
		if (tm <= k) ans++;
		else {

			break;
		}
	}
	if (tm < k) {
		if (tp < n) {
			while (tp < n && tm < k) {
				tm += a[tp];
				tp++;
				if (tm <= k) ans++;
				else break;
			}
		} else if (bt < m) {
			while (bt < m && tm < k) {
				tm += b[bt];
				bt++;
				if (tm <= k) ans++;
				else break;
			}
		}
	}
	// dfs(0, 0, 0, 0);
	cout << ans << endl;
	return 0;
}
