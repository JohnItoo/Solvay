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

string trUpp(string s) {

	transform(s.begin(), s.end(), s.begin(), ::toupper);
	return "";
}

int main() {
	vector<int> ds;
	int mod = 1073741824;
	int ans = 1;

	int a, b, c; cin >> a >> b >> c;

	vector<int> sieve(105, 0);


	for (int i = 2; i <= 100; i++) {
		if (sieve[i]) continue;
		for (int j = i; j <= 100; j += i) {
			sieve[j] = i;
		}
	}
	vi primes;
	for (int i = 2; i <= 100; i++) {
		int x = sieve[i];
		if (x == i || !x) {
			primes.pb(i);
		}
	}

	REP(i, 1, a) {
		REP(j, 1, b) {
			REP(k, 1, c) {
				if (i * j * k == 1) continue;
				int prod = i * j * k;
				int start = 0;
				int ct = 0;
				vector<int> alphasi;
				while (prod > 1) {
					// cout << prod << "\n";
					while (start < primes.size() && prod % primes[start] == 0) {
						ct++;
						prod /= primes[start];
					}

					if (ct > 0) {
						alphasi.pb(ct);
						ct = 0;
					}
					start++;
				}
				int factors = 1;
				for (int factori : alphasi) {
					factors *= factori + 1;
				}

				ans += factors;
				ans %= mod;
			}
		}
	}
	cout << ans << "\n";

	return 0;
}
