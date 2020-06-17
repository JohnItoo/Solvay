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
// bool comp(ii a, ii b) {
// 	return a.first > b.first;
// }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;

	vii pairs;
	forn(i, m) {
		int x, y; cin >> x >> y;
		pairs.pb(mp(x, y));
	}
	sort(pairs.begin(), pairs.end());
   
    if(pairs[0].first != 1) {
    	cout << -1 << endl;
    	return 0;
    }
	ii prev = mp(0, 0);
	int ans = 0;
	string sb = "";
	forn(i, m) {
		ii curr = pairs[i];
		if (curr.first == prev.first && curr.second != prev.second) {
			ans = -1;
			break;
		}
		if (curr.first == prev.first) continue;
		if (curr.first  > prev.first + 1) {
			int ct = curr.first - prev.first - 1;
			forn(j, ct) sb.pb('0');
		}
		sb += to_string(curr.second);
		prev = curr;
	}
	if (ans == -1) {cout << ans << endl;}
	else
		cout << stoi(sb) << endl;
	return 0;
}
