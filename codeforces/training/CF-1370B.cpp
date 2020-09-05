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
	int tc;
	cin >> tc;
	while (tc--) {
		int n; cin >> n;
		set<ii> st;
		vector<ii> odds;
		vector<ii> evs;
		vector<ii> result;
		forn(i, n * 2) {
			int a; cin >> a;
			if (a & 1) odds.pb(make_pair(a, i));
			else evs.pb(make_pair(a, i));
		}
		if (odds.size() < evs.size()) {
			int q = 0;
			while (q + 1 < odds.size() - 2) {
				ii pr = mp(odds[q].second + 1, odds[q + 1].second + 1);
				result.pb(pr);
				q += 2;
			}
			if (q < odds.size() - 2) {
				st.insert(odds[q]);
			}
			forn(i, evs.size()) {
				st.insert(evs[i]);
				if (st.size() == (2 * n) - 2) break;
			}
		} else {
			int q = 0;
			int ct = 0;
			while (q + 1 < evs.size() - 2) {
				ii pr = mp(evs[q].second + 1, evs[q + 1].second + 1);
				result.pb(pr);
				q += 2;
				ct += 2;
			}
			if (q < evs.size() - 2) {
				st.insert(evs[q]);
				ct += 1;
			}
			cout << ct << "\n";

			forn(i, odds.size()) {
				st.insert(odds[i]);
				if (st.size() == ((2 * n) - 2) ) break;
			}
		}

		while (st.size() != 0) {
			auto it = st.begin();
			ii fr = *it;
			auto iit = st.erase(it);
			ii sec;
			if (iit != st.end()) {
				sec =  *iit;
			}

			st.erase(iit);

			result.pb(fr);
			result.pb(sec);
		}

		forn(i, result.size()) {
			cout << result[i].first << " " << result[i].second << "\n";
		}

	}
	return 0;
}
