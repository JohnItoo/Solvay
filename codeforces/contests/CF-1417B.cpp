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
	int tc; cin >> tc;
	while (tc--) {
		int n, t;
		cin >> n >> t;
		vector<int> a(n);
		set<ii> st;
		forn(i, n) {
			cin >> a[i];
			st.insert(mp(a[i], i));
		}
		vi res(n);
		set<int> ones;
		set<int> zeros;
		while (st.size() > 1) {
			auto it = st.begin();
			ii curr = *it;
			st.erase(it);

			it = st.lower_bound(mp(t - curr.first, 0));

			if (it != st.end() && t - curr.first == (*it).first) {
				res[curr.second] = 1;
				res[(*it).second] = 0;
				ones.insert(curr.first);
				zeros.insert((*it).first);
				st.erase(it);
			} else {
				res[curr.second] = 1;
				ones.insert(curr.first);
			}
		}
		if (st.size() != 0) {
			int nd = (*st.begin()).first;

			if (zeros.lower_bound(abs(t - nd)) != zeros.end()) {
				int ds = *zeros.lower_bound(abs(t - nd));
				// cout << ds << " " << t - nd << "\n";
				if (ds == t - nd) {
					res[nd] = 1;
				} else {
					res[nd] = 0;
				}
			} else {
				res[nd] = 0;

			}
		}

		forn(i, n) cout << res[i] << " ";
		cout << "\n";


	}
	return 0;
}
