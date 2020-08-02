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
	int m, s;
	cin >> m >> s;


	vector<vector<int> > mxx(s + 1, vector<int>(m + 1, -1));
	vector<vector<int> > mnn(s + 1, vector<int>(m + 1, 900));

	for(int i = 1; i <= min(9, s); i++) {
		mxx[i][1] = i;
		mnn[i][1] = i;
	}

	for (int i = 1; i <= s; i++) {
		for (int k = 1; k <= m; k++) {
			for (int j = 1; j <= min(9, i); j++) {
				if (i > 9 && k == 1) continue;
				// if(mnn[i][k] == 900) mnn[i][k] = j;
				if (mnn[i-j][k-1] != 900) mnn[i][k] = min(mnn[i][k], j);

				if(mxx[i][k] == -1) mxx[i][k] = j;
				else mxx[i][k] = max(mxx[i][k], j);
			}
		}
	}


	for(int i = 0; i <=s; i++) {
		for(int j = 0; j <=m; j++) {
			cout << mxx[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}
