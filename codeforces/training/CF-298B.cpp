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
	int t, sx, sy, ex, ey; cin >> t >> sx >> sy >> ex >> ey;
	string s; cin >> s;
	int n = s.length();
	t -= 1;
	int i = 0;
	while (i < t && i < n) {
		int mvx = sx, mvy = sy;
		int prev = abs(ex - sx) + abs(ey - sy);
		if (s[i] == 'S') mvy -= 1;
		if (s[i] == 'N') mvy += 1;
		if (s[i] == 'W') mvx -= 1;
		if (s[i] == 'E') mvx += 1;

		int man = abs(ex - mvx) + abs(ey - mvy);

		if (man < prev) {
			sx = mvx;
			sy = mvy;
		}

		if (man == 0) {
			cout << i + 1 << endl;
			return 0;
		}
		i++;
	}
	cout << -1 << endl;
	return 0;
}
