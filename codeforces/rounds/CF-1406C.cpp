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
	int tc;
	cin >> tc;
	while (tc--) {
		int n; cin >> n;
		vector <vector<int>> tree(n + 1, vector<int>());
		ii fst = mp(0, -1);
		ii sec = mp(0, -1);
		forn(i, n - 1) {
			int x, y; cin >> x >> y;
			tree[x].pb(y);
			tree[y].pb(x);
			if (tree[x].size() > fst.first) {
				sec = fst;
				fst = mp(tree[x].size(), x);
			} else if (tree[x].size() > sec.first) {
				sec =  mp(tree[x].size(), x);
			}

			if (tree[y].size() >= fst.first) {
				sec = fst;
				fst = mp(tree[y].size(), x);
			} else if (tree[y].size() >= sec.first) {
				sec =  mp(tree[y].size(), x);
			}
		}

		if (fst.first == sec.first) {
			map<int, int> hasfst;
			for (int ed : tree[fst.second]) {
				hasfst[ed]++;
			}
			int torem = 0;
			for (int ed : tree[sec.second]) {
				if (hasfst.find(ed) == hasfst.end()) {
					torem = ed;
				}
			}

			cout << torem << " " << sec.second << "\n";
			cout << torem << " " << fst.second << "\n";

		} else {
			cout << fst.second << " " << tree[fst.second][0] << "\n";
			cout << fst.second << " " << tree[fst.second][0] << "\n";
		}

	}
	return 0;
}
