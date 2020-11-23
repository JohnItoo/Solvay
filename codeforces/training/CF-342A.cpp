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
	int n; cin >> n;
	vector<int> a(n);
	map<int, int> freq;
	forn(i, n) {
		cin >> a[i];
		freq[a[i]]++;
	}
	int ones = freq.find(1) != freq.end() ? freq[1] : 0;
	int  twos = freq.find(2) != freq.end() ? freq[2] : 0;
	int threes =  freq.find(3) != freq.end() ? freq[3] : 0;
	int fours = freq.find(4) != freq.end() ?  freq[4] : 0;
	int sixes = freq.find(6) != freq.end() ? freq[6] : 0;

	if (freq.find(1) != freq.end()) {
		if (freq[1] != n / 3) {
			cout << -1 << endl;
			return 0;
		} else {
			ones = n / 3;
		}

	} else {
		cout << -1 << endl;
		return 0;
	}

	if (freq.find())

		return 0;

}
