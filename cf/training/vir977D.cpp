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
vector<ll> curr;
bool found = false;


void perm(ll st, int n, int targ, vector<ll> vl) {
	if (curr.size() == targ) {
		bool locfound = true;
		for (int i = 0; i < curr.size(); i++) {
			cout << curr[i] << "curr";
		}
		cout << endl;
		for (int i = 0; i < curr.size(); i++) {
			if (find(vl.begin(), vl.end(), curr[i]) ==  vl.end()) {
				locfound = false;
				break;
			}
		}
		if (locfound) {
			for (auto id : curr) {
				cout << id  << " ";
			}
			cout << endl;
		}
		found = locfound;
		return;
	}
	bool cont = true;
	if (found) return;
	curr.pb(st);
	// cout << st << endl;
	forn(i, 2) {
		if (i == 0) {
			perm(st * 2, n + 1, targ, vl);
		} else {
			if (n % 3 == 0) {
				perm(st / 3, n + 1, targ, vl);
			}
			
		}
	}
	curr.pop_back();
	if (!cont) return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	found = false;

	int n; cin >> n;
	vector<ll> vl;
	forn(i, n) {
		int x; cin >> x;
		vl.pb(x);
	}
	for (ll st : vl) {
		curr.clear();
		perm(st, 0, n, vl);

		if (found) {
			cout << "found";

			break;
		}
	}
	return 0;
}

int permutaion() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<ll> vl;
	forn(i, n) {
		ll x; cin >> x;
		vl.pb(x);
	}

	do {
		bool correct = true;
		for (int i = 0; i < n - 1; i++) {
			if ((vl[i] * 2 != vl[i + 1]) && !((vl[i] % 3 == 0) && (vl[i] / 3 == vl[i + 1]))) {
				correct = false;
				break;
			}
		}
		if (correct) break;

	} while (next_permutation(vl.begin(), vl.end()));

	for (auto cc : vl) {
		cout << cc << " ";
	}
	cout << endl;

	return 0;

}
