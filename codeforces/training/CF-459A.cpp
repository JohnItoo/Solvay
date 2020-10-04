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
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int x3 = 0, y3 = 0, x4 = 0, y4 = 0;
	if (x1 == x2) {
		if (y1 < y2) {
			swap(y1, y2);
		}
		int diff =  y1 - y2;
		x3 = x1 + diff;
		y3 = x1;

		x4 = x3;
		y4 = y2;
	} else if (y1 == y2) {
		if (x1 < x2) swap(x1, x2);

		int diff = x1 - x2;

		x3 = x2;
		y3 = y2 + diff;

		x4 = x1;
		y4 = y3;
	} else {
		// if(x1 < x2) {
		// 	swap(x1, x2);
		// 	swap(y1, y2);
		// }

		x3 = x1;
		y3 = y2;
		x4 = x2;
		y4 = y1;
	}
	cout << x3 << " " << y3 << " " << x4 << " " << y4 << "\n";
	return 0;
}
