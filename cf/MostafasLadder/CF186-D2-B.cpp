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
// to_string(int)

string trUpp(string s) {

	transform(s.begin(), s.end(), s.begin(), ::toupper);
	return "";
}

bool comp(pair<double, int> a, pair<double, int> b) {
	if (a.first == b.first) return a.second > b.second;
	else return a.first < b.first;

}
int main() {
	double n, ta, tb, k;
	cin >> n >> ta >> tb >> k;
	vector<pair<double, int> > res(n);
	forn(i, n) {
		double v1, v2; cin >> v1 >> v2;
		double opt1 = ((v1 * ta) - ((v1 * ta) * (k / 100))) + (v2 * tb);
		double opt2 = ((v2 * ta) - ((v2 * ta) * (k / 100))) + (v1 * tb);
		res[i] = mp(max(opt1, opt2), i + 1);
	}
	sort(res.begin(), res.end(), comp);
	for (int i = n - 1; i >= 0; i--) {
		pair<double, int> curr = res[i];
		printf("%d %.2f\n", curr.second,  curr.first);

	}
	return 0;
}
