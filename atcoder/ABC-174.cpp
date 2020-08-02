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

int A() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	if (n >= 30) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}

int B() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, d;
	cin >> n >> d;
	int an = 0;
	while (n--) {
		double x, y; cin >> x >> y;
		double dis = (x * x) + (y * y);
		if (dis <= d * d) {
			an++;
		}
	}
	cout << an << "\n";
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string s ; cin >> s;
	string org = s;
	 int fr = 0, sc = 0;
	 forn(i, n-1) {
	 	if(s[i] == 'W' && s[i+1] == 'R') {
	 		s[i] = 'R';
	 		fr++;
	 	}
	 }
	 s = org;
	 forn(i, n-1) {
	 	if(s[i] == 'W' && s[i] == 'R') {
	 		s[i+1] = 'W';
	 		sc++;
	 	}
	 }
	 cout << min(sc, fr) << "\n";
	return 0;
}
