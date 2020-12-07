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

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int a, b;
	cin >> a >> b;
	if (a == b) {
		cout << 0 << "\n";
		return 0;
	}
	int div = gcd(a, b);
	a /= div; b /= div;
	int orga = a;
	int orgb = b;
	int ans = 0;

	for (int x = 2; x <= 5 && a > 1; x++) {
		if (x > 5) {
			cout << -1 << endl;
			return 0;
		}
		while (a % x == 0) {
			ans++;
			a /= x;
		}
	}
	if (a > 1) {
		cout << -1 << endl;
		return 0;
	}

	for (int x = 2; x <= 5 && b > 1; x++) {
		if (x > 5) {
			cout << -1 << endl;
			return 0;
		}
		while (b % x == 0) {
			ans++;
			b /= x;
		}
	}
	if (b > 1) {
		cout << -1 << endl;
		return 0;
	}
	cout << ans << endl;




	return 0;
}
