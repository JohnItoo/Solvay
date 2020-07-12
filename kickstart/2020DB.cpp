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

string trUpp(string s) {

	transform(s.begin(), s.end(), s.begin(), ::toupper);
	return "";
}
// sorts with second in descending order and if second is equal sorts with first if descending order
bool sortPairs(ii &a,  ii &b) {
	if (a.second == b.second) return a.first > b.first;
	else return a.second > b.second;
}

void solve() {
	int n;
	cin >> n;
	int a[n];
	char ch[] = {'a', 'b', 'c', 'd'};
	string seq;
	forn(i, n) {
		cin >> a[i];
		seq.pb('a' + (i % 4));
	}
	// cout << seq << "\n";
	string word = "";
	int sol = INF;
	forn(k, 4) {
		word = "";
		forn(j, n) {
			word.pb(ch[(k + j) % 4]);
		}
		seq = word;
		int ans = 0;
		forn(i, n - 1) {
			if ((a[i] < a[i + 1] && seq[i] > seq[i + 1]) || (a[i] > a[i + 1] && seq[i] < seq[i + 1])) {
				ans++;
				// cout << a[i] << " " << a[i+1] << " " << seq[i] << " " << seq[i+1] << "\n";
			}
		}
		sol = min(sol, ans);
	}


	cout << sol << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc ; cin >> tc;
	forn(i, tc) {
		cout << "Case #" << i + 1 << ": ";
		solve();
	}
	return 0;
}
