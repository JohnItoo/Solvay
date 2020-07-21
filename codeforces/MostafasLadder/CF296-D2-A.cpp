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

//WA 34
string trUpp(string s) {

	transform(s.begin(), s.end(), s.begin(), ::toupper);
	return "";
}

int main() {
	int n; cin >> n;
	int a[n];
	forn(i, n) cin >> a[i];
	sort(a, a + n);
	vi amt; amt.pb(a[0]);
	map<int, int> fq; fq[a[0]] = 1;
	REP(i, 1, n - 1) {
		int x = a[i];
		fq[x]++;
		if (a[i - 1] != x) {
			amt.pb(x);
		}
	}
	if (amt.size() == 1) {
		string ans = fq.find(amt[0])-> second > 1 ? "NO" : "YES";
		cout << ans << endl;
		return 0;
	}
	string ans = "NO";
	forn(i, amt.size()) {
		int wt = fq.find(amt[i])->second;
		if (wt <= 0) continue;
		wt -= 1;
		forn(j, amt.size()) {
			if (i == j) continue;

			int xx = fq.find(amt[j])->second;

			if (xx <= 0) continue;
			if (wt - xx > 0) {
				fq[amt[j]] = 0;
				wt -= xx;
			} else {
				fq[amt[j]] = xx - wt;
				wt = 0;
			}
		}
		if (wt == 0) {
			ans = "YES";
			break;
		}
	}
	cout << ans << endl;



	return 0;
}
