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
		int n; cin >> n;
		int a, b, c; cin >> a >> b >> c;
		string s; cin >> s;
		int x = 0, y = 0, z = 0;
		forn(i, s.length()) {
			if (s[i] == 'R') y++;
			else if (s[i] == 'P') z++;
			else x++;
		}
		int tot = min(a, x) + min(b, y) + min(c, z);
		if (tot < (n + 1) / 2) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			string ans;
			forn(i, n) {
				if (s[i] == 'S' && a > 0) {
					ans.pb('R');
					a--;
				} else if (s[i] == 'R' && b > 0) {
					ans.pb('P');
					b--;
				} else if (s[i] == 'P' && c > 0) {
					ans.pb('S');
					c--;
				} else {
					if (a > 0) {
						ans.pb('R');
						a--;
					} else if (b > 0) {
						ans.pb('P');
						b--;
					} else {
						ans.pb('S');
						c--;
					}
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
