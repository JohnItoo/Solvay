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
	int n, m , x; cin >> n >> m >> x;
	int a[n][m]; int c[n];
	forn(i, n) {
		cin >> c[i];
		forn(j, m) {
			cin >> a[i][j];
		}
	}
	cout << c[0] << endl;
	int dp[100008][16];
	memset(dp, MEMSET_INF, sizeof dp);

	REP(i, 1, m) { // cols for each col.
		REP(j, 1, x) { // rows amounts
			REP(k, 1, n) {
				if (a[k - 1][i - 1] + j - 1 < j) continue;
				if (a[k - 1][i - 1] >= j) {
					REP(l, j , j + a[k - 1][i - 1] - 1) {
						dp[l][i] = min(dp[l][i], c[k - 1]);
					}
				} else {
					dp[j][i] = min(dp[j][i], dp[j - 1][i] + c[k - 1]);
				}
			}

		}
	}

	int ans = -1;
	REP(i, 1, m) {
		if (dp[x][i] == INF) {
			ans = -1;
			break;
		}
		cout << dp[x][i] << endl;
		ans = max(ans , dp[x][i]);
	}

	cout << ans << endl;

	return 0;

}
