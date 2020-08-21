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

bool isPrime(int x) {
	return (x == 2 || x == 3 || x == 5 || x == 7);
}

int main() {
	int n; cin >> n;
	string s; cin >> s;
	sort(s.begin(), s.end());
	set<int> brks;
	map<int, int> mp;
	mp.clear();
	bool allPrime = true;
	int arr[8][4] = { {1, 0, 0, 0}, {1, 1, 0, 0}, {3, 1, 0, 0}, {4, 2, 1, 0}, {5, 2, 1, 0}, {4, 2, 1, 1}, {7, 2, 1, 1}, {7, 4, 1, 1}};
	int primes[4] = {2, 3, 5, 7};
	for (int i = n - 1; i >= 0; i--) {
		int curr = s[i] - '0';
		if (curr < 2) continue;
		if (isPrime(curr) && curr != 3) {
			mp[curr]++;
		} else {
			forn(i, 4) {
				if (arr[curr - 2][i] > 0) {
					mp[primes[i]] += arr[curr - 2][i];

				}
			}
		}

	}

	if (mp.find(3) != mp.end() && mp.find(2) != mp.end()) {
		mp[2] -= mp.find(3)->second;
	}

	string ans = "";

	for (int i = 3; i >= 0; i--) {
		if (mp.find(primes[i]) != mp.end()) {
			int times = mp.find(primes[i])->second;
			char c = (char) primes[i] + '0';
			string suff = string(times, c);
			ans += suff;
		}
	}
	cout << ans << "\n";
	return 0;
}
