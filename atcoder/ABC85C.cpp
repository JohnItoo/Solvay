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
int lm = 2e4 + 5;

bool dp[20005][2000][4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int use[3] = {1, 5, 10};
	// memset(dp, -1, sizeof dp);

	dp[0][0][0] = true;
	int n, y; cin >> n >> y;
	y /= 1000;

	for (int amt = 1; amt <= y; amt++) {
		for (int times = 1; times <= n; times++) {
			for (int coins = 1; coins <= 3; coins++) {
				int value = use[coins - 1];
				if (amt < value) break;

				dp[amt][times][coins] = (dp[amt - value][times - 1][1]
				                         || dp[amt - value][times - 1][2] || dp[amt - value][times - 1][3]) ?  1 : -1;
			}
		}
	}
	if (!dp[y][n][1] || !dp[y][n][2] || !dp[y][n][3]) {
		cout << -1 << " " << -1 << " " << -1 << endl;
	} else {

	}
	return 0;
}
