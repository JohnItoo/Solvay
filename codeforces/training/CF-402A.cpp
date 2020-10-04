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
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization tables
//memset(arr, 0, sizeof arr); // useful to clear array of integers
int k, a, b, v;

int makeboxes(int rembs) {
	if (rembs < k) {
		int sections = b + 1;
		int currboxes = 1;
		a -= (sections) * v;
		if (a > 0) {
			currboxes += (a + v - 1) / v;
		}
		return currboxes;
	}

	int boxes = rembs / k;
	int newrembs = rembs - (boxes * (k - 1));
	int nuts = boxes * k * v;
	a -= nuts;
	return boxes + makeboxes(newrembs);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> k >> a >> b >> v;
	cout << makeboxes(b) << "\n";
}

return 0;
}
