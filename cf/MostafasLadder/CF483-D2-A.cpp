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

int main() {
	ll l, r; cin >> l >> r;
	int sv[55];
	memset(sv, 0, 55);

	for (int i = 2; i * i <= 50; i++) {
		if (sv[i]) continue;
		for (int j = i * 2; j <= 50; j += i) {
			sv[j] = i;
		}
	}
	vector<int> primes;
	REP(i, 2, 50) {
		if (sv[i] == 0) primes.pb(i);
	}
	bool found = false; ll a = -1; ll b = -1;  ll c = -1; bool comp = false; int fp = -1;
	for (int prime : primes) {
		int num = 0;
		for (ll i = l; i <= r; i++) {
			if (i % prime != 0) continue;
			num++;
			if (found) {
				if(i % fp != 0) {
					c = i;
					break;
				}

			} else {
				if (a == -1) a = i;
				else if (b == -1) b = i;

				if (num == 2) {
					found = true;
					fp = prime;
					break;
				}
			}

		}
		if(a != -1 && b != -1 && c != -1) break;
	}

	if(a == -1 || b == -1 || c == -1)  cout << -1 << endl;
	else {
		ll res[3] = {a, b , c};
		sort(res, res+3);
		cout << res[0] << " " << res[1] << " " << res[2] << endl;
	}


	return 0;

}
