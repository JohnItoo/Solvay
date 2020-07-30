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
//WA
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		ii arr[n];
		forn(i, n) {
			int x, y ; cin >> x >> y;
			arr[i] = mp(x, y);
		}
		string ans = "YES";
		if ( n == 1) {
			ans = arr[0].first >= arr[0].second ? "YES" : "NO";
			cout << ans << endl;
			return 0;
		}
		forn(i,  n) {
			REP(j, i + 1, n - 1) {
				int currclears = arr[j].second;
				int prevclears  = arr[i].second;
				int currplays = arr[j].first;
				int prevplays = arr[i].first;

				if (currclears < prevclears || currplays < prevplays || (currclears > prevclears && prevplays == currplays) || currclears > currplays || prevclears > prevplays) {
					ans = "NO";
					break;
				}
			}

		}
		cout << ans << endl;
	}
	return 0;
}