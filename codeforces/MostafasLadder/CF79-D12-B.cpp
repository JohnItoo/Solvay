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
// to_string(int)

string trUpp(string s) {

	transform(s.begin(), s.end(), s.begin(), ::toupper);
	return "";
}

int main() {
	int n, m, k, t; cin >> n >> m >> k >> t;
	vi waste;
	forn(i, k) {
		int a, b; cin >> a >> b;
		int idx = (a * m) - m + b;
		waste.pb(idx);
	}
	sort(waste.begin(), waste.end());

	vi queries;
	forn(i, t) {
		int a, b; cin >> a >> b;
		int idx = (a * m) - m + b;
		queries.pb(idx);
	}

	for (auto query : queries) {
		bool isWaste = false;
		int nos = 0;
		forn(i, waste.size()) {
			if (waste[i] == query) {
				isWaste = true;
				break;
			}
			if (waste[i] > query) {
				break;
			}
			nos++;
		}

		if (isWaste) {
			cout << "Waste" << endl;
		} else {
			query -= nos;
			if (query % 3 == 0) cout << "Grapes" << endl;
			else if (query % 3 == 1) cout << "Carrots" << endl;
			else cout << "Kiwis" << endl;
		}
	}
	return 0;
}
