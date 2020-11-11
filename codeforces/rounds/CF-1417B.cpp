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
		map<int, vector<int> > mp;
		forn(i, n) {
			cin >> a[i];
			mp[a[i]].pb(i);
		}

		vector<int> res(n, -1);

		forn(i, n) {
			if (res[i] != -1) continue;
			res[i] = 0;
			int fd = t - a[i];
			if (fd == a[i]) {
				int next = 1;
				vector<int> curr = mp[fd];

				for (int val : curr) {
					if (val == i) continue;
					res[val] = next;
					next = next == 1 ? 0 : 1;
				}

			} else {
				if (mp.find(fd) != mp.end()) {
					vector<int> curr = mp[fd];
					for (int val : curr) {
						res[val] = 1;
					}
				}
			}
		}

		forn(i, n) cout << res[i] << " ";
		cout << endl;




	}
	return 0;
}
