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
	int n, m;
	cin >> n >> m;
	string a, b; cin >> a >> b;

	int lcs[n + 1][m + 1];

	REP(i, 0, n) {
		REP(j, 0,  m) {
			if (i == 0 || j == 0) {
				lcs[i][j] =  0;
			} else if (a[i - 1] == a[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			} else {
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}

		}
	}
	int index = lcs[n][m];

	char res[index + 1];
	res[index] = '\0'; // Set the terminating character
	string here = "";

	int i = n, j = m;
	while (i > 0 && j > 0)
	{

		if (a[i - 1] == b[j - 1])
		{
			here.pb(a[i - 1]);
			res[index - 1] = a[i - 1]; // Put current character in result
			i--; j--; index--;     // reduce values of i, j and index

		}

		else if (lcs[i - 1][j] > lcs[i][j - 1])
			i--;
		else
			j--;
	}
	string mylcs = "";
	forn(i, lcs[n][m]) {
		mylcs.pb(res[i]);
	}
	reverse(here.begin(), here.end());
	int pt = 0;
	int cst = 1e9 + 8;
	int mna = 1e9 + 8;
	int mnb = 1e9 + 8;
	for (int i = 0; i < n; i++) {
		pt = 0;

		if (here[pt] != a[i]) continue;
		int mv = i;
		while (pt < here.length() &&  mv < n) {
			if (here[pt] != a[mv]) {
				mv++;
				continue;
			}
			pt++;
			mv++;
		}
		// cout << pt << "pt \n";
		if (pt == here.length()) {
			mna = min(mna, mv - i);
		}

	}

	for (int i = 0; i < m; i++) {
		pt = 0;
		if (here[pt] != b[i]) continue;
		int mv = i;
		while (pt < here.length() &&  mv < n) {
			if (here[pt] != b[mv]) {
				mv++;
				continue;
			}
			pt++;
			mv++;
		}
		if (pt == here.length()) {
			mnb = min(mnb, mv - i);
		}
	}

	if (mna == cst || mnb == cst) {
		cout << 0 << endl;
	} else {
		ll ans = (4 * here.length() ) - mnb - mna;
		cout << ans << endl;
	}


	return 0;
}
