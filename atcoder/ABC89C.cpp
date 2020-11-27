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
	map<char, ll> fq;
	int n; cin >> n;
	ll m = 0, a = 0, r = 0, c = 0, h = 0;
	forn(i, n) {
		string s; cin >> s;
		char ch = s[0];
		if (ch ==  'M') m++;
		else if (ch == 'A') a++;
		else if (ch == 'R') r++;
		else if (ch == 'C') c++;
		else if (ch == 'H') h++;
	}
	fq['M'] = m; fq['A'] = a; fq['R'] = r; fq['C'] = c; fq['H'] = h;
	vector<char> vcc;
	if (m > 0) vcc.pb('M');
	if (a > 0) vcc.pb('A');
	if (r > 0) vcc.pb('R');
	if (c > 0) vcc.pb('C');
	if (h > 0) vcc.pb('H');
	if (vcc.size() < 3) {
		cout << 0 << endl;
		return 0;
	}

	ll ans = 0;

	for (int i = 0; i + 2 < vcc.size(); i++) {
		for (int j = i + 1; j + 1 < vcc.size(); j++) {
			for (int k = j + 1; k < vcc.size(); k++) {
				ll ways = (ll) (fq[vcc[i]] * fq[vcc[j]] * fq[vcc[k]]);
				ans  += ways;

			}
		}
	}

	cout << ans << endl;



	return 0;
}
