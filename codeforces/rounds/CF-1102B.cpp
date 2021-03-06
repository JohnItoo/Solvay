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
	int n, k;
	cin >> n >> k;
	set<ii> p;
	map<int, int> mps;
	bool cant = false;
	forn(i, n) {
		int x; cin >> x;
		p.insert(mp(x, i));
		if (mps.find(x) != mps.end()) {
			cant = (mps.find(x)->second + 1) > k;
		}
		mps[x]++;
	}
	if (cant || k > n) {
		cout << "NO";
		return 0;
	}

	vector<int> res(n);

	int last = 1;
	int curr = 1;
	while (!p.empty()) {
		auto it = p.begin(); ii  tp = *it;
		p.erase(it);
		last = tp.first;
		curr = 1;
		res[tp.second] = curr++;
		while (p.size() != 0) {
			if ((*p.begin()).first != last) break;
			res[(*p.begin()).second] = curr++;
			p.erase(p.begin());
		}
	}

	cout << "YES\n";
	forn(i, n) {
		cout << res[i] << " ";
	}

	return 0;
}
