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
	vector<int> nm;
	int x; cin >> x;
	int i = 1;
	while (i <= x) {
		i *= 9;
		nm.pb(i);
	}

	i = 1;
	while (i <= x) {
		i *= 6;
		nm.pb(i);
	}
	sort(nm.rbegin(), nm.rend());

	int j = 0;
	int ans = 0;
 	while (j < nm.size()) {
		if (x < nm[j]) {
			j++;
		} else {

			int ct = x / nm[j];
			int nx = x - nm[j] * ct;
			cout << nx << "nx\n";
			while(j + 1 < nm.size() && x > nm[j+1]  && x - (nm[j+1] * (x/nm[j+1]) <= nx)) {
				j++;
				cout << nm[j] << " "<< x - (nm[j] * (x/nm[j])) << " nmj\n";
			}
			cout << "stop\n";
			if(j == nm.size()) j--;
			x -= ct * nm[j];
			cout << x << " nwx\n";
			ans += ct;
			j++;
		}
	}

	if(x > 0) ans += x;
	cout << ans << endl;




	return 0;
}
