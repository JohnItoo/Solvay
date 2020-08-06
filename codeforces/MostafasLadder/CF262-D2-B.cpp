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
// to_string(int)

string trUpp(string s) {

	transform(s.begin(), s.end(), s.begin(), ::toupper);
	return "";
}

int main() {
	int n, k;
	cin >> n >> k;
	int a[n];
	int negs = 0;
	int lastneg = 0;
	forn(i, n) {
		cin >> a[i];
		if (a[i] < 0) {
			negs++;
			lastneg = i;
		}
	}

	if (negs < k) {
		if (negs == 0) {
			if (k & 1) {
				a[0] = -a[0];
			}
		} else {
			int i = 0;
			while (i < negs) {
				a[i] = abs(a[i]);
				i++;
			}
			if ((k - negs) & 1) {
				if (lastneg + 1 < n  && abs(a[lastneg]) > a[lastneg + 1]) {
					a[lastneg + 1] = -a[lastneg + 1];
				} else {
					a[lastneg] = -a[lastneg];
				}
			}
		}

	} else {

		int i = 0;

		while (i < k) {
			a[i] = abs(a[i]);
			i++;
		}

	}

	ll sm = 0;
	forn(i, n) sm += a[i];

	cout << sm << "\n";


	return 0;
}
