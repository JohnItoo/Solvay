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

bool dp[20005][2005][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int use[3] = {1, 5, 10};
	// memset(dp, -1, sizeof dp);



	dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = true;
	forn(i, 3) {
		dp[use[i]][1][0] = dp[use[i]][1][1] = dp[use[i]][1][2] = true;
	}

	int n, y; cin >> n >> y;
	y /= 1000;

	for (int amt = 1; amt <= y; amt++) {
		for (int times = 1; times <= n; times++) {
			// if (times > amt) continue;
			for (int coins = 1; coins <= 3; coins++) {
				int value = use[coins - 1];
				if (amt < value) break;

				dp[amt][times][coins - 1] = (dp[amt - value][times - 1][0] || dp[amt - value][times - 1][1] || dp[amt - value][times - 1][2]);

			}
		}

	}
	// forn(i, 3) cout << dp[10][1][i] << endl;
	// return 0;

	map<int, int> hw;
	int amt = y;
	int times = n;

	if (!dp[y][n][0] &&  !dp[y][n][1] && !dp[y][n][1]) {
		cout << -1 << " " << -1 << " " << -1 << endl;
	} else {
		while (times > 0) {
			if (dp[amt][times][0]) {
				amt -= use[0];
				hw[use[0]]++;
				times--;
			} else if (dp[amt][times][1]) {
				amt -= use[1];
				hw[use[1]]++;
				times--;
			} else {
				amt -= use[2];
				times--;
				hw[use[2]]++;
			}
		}
		for (int i = 2; i >= 0; i--) {
			if (hw.find(use[i]) == hw.end()) cout << 0 << " ";
			else cout << hw[use[i]] << " ";
		}
		cout << endl;
	}






	return 0;
}
