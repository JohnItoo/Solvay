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
		// cout << "new line\n";
		int n; cin >> n;
		vector<string> strings;

		vector<int> counts(n, 0);
		int mx = 0;
		forn(i, n) {
			int ct = 0; cin >> ct;
			counts[i] = ct;
			mx = max(ct, mx);
		}
		if (mx == 0) {
			int ff = 0;

			string tp = string(1, 'a');
			strings.pb(tp);
			forn(i, n) {
				ff += 1;
				char newCh = (char) ((ff % 26) + 'a');
				string ntp = string(1, newCh);
				strings.pb(ntp);
			}
		}
		else {
			string last = string(mx + 1, 'a');
			strings.push_back(last);
			int ch = 0;
			forn(i, n) {
				int ct = counts[i];
				if (ct <= last.length()) {
					if (ct == 0) {
						ch += 1;
						char newCh = (char) ((ch % 26) + 'a');
						string newStr = string(mx, newCh);
						last = newStr;
					} else {
						last = last.substr(0, ct);
						ch += 1;
						char newCh = (char) ((ch % 26) + 'a');
						string app = string(mx - ct, newCh);
						last += app;
					}
				} else {
					char newCh = (char) ((ch % 26) + 'a');
					string add = string(mx, newCh);
					last = add;
				}
				strings.push_back(last);
			}
		}

		forn(i, strings.size()) {
			cout << strings[i] << "\n";
		}
	}
	return 0;
}
