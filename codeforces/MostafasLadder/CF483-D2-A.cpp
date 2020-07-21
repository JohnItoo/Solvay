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
	//WA

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
	ll a = -1; int prima = 0;
	for (ll i = l; i  <= r ; i++) {
		for (auto prime : primes) {
			if (i % prime == 0) {
				a = i;
				prima = prime;
				break;
			}
		}
		if (a != -1) break;
	}
	ll primeb = -1; ll sec = -1;
	for (ll i = a + 1; i <= r; i++) {
		bool fd = false;
		for (auto prime : primes) {
			if (i % prime) {
				fd = true;
				primeb = prime;
				sec = i;
				break;
			}
		}
		if (fd) break;
	}
	ll b = -1;
	if (sec == -1) cout << sec << endl;
	else {
		ll third = -1;
		for (ll i = sec + 1; i <= r; i++) {
			if (i % prima == 0 && i % primeb != 0) {
				third = i;
				break;
			}
		}
		if (third == -1) cout << third << endl;
		else cout << a << " " << sec << " " << third << endl;

	}
	return 0;

}