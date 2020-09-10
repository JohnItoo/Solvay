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

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		int n; cin >> n;
		vi a(n);
		forn(i, n) cin >> a[i];
		// sort(a.rbegin(), a.rend());
		auto idxst = max_element(a.begin(), a.end());
		int st = *idxst;
		vi b(n);
		vector<bool> dn(n, false);
		dn[idxst - a.begin()] = true;
		b[0] = st;
		int i = 1;

		while (i < n && st > 1) {

			int currmx = 0;
			int curridx = 0;
			forn(j , n) {
				if (dn[j]) continue;

				if (gcd(st, a[j]) > currmx) {
					currmx = gcd(st, a[j]);
					curridx = j;
				}
			}

			b[i] = a[curridx];
			dn[curridx] = true;
			st = b[i];
			i++;
		}

		forn(j, n) {
			if (!dn[j]) {
				b[i] = a[j];
				i++;
			}
		}


		for (int val : b) {
			cout << val << " ";
		}

		cout << "\n";
	}
	return 0;
}
