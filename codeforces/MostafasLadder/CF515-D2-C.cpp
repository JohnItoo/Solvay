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
	int arr[4] = {2, 3, 5, 7};
	sort(s.begin(), s.end());
	set<int> brks;
	map<int, int> mp;
	mp.clear();
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		int curr = s[i] - '0';
		cout << "This is curr " << curr << "\n";
		if (isPrime(curr)) {
			brks.insert(curr);
			while (curr > 1) {
				mp[curr]++;
				curr--;
			}
		} else {
			int sp = 0;
			int start = curr;
			cout << "STRANGE!!" << "\n";
			while (start > 1 && sp < 4) {
				cout << "THis is sp" << arr[sp] << "\n";
				if (start % arr[sp] == 0) {
					mp[arr[sp]]++;
					start /= arr[sp];
					brks.insert(arr[sp]);
				} else {
					sp++;
				}
			}
		}
	}

	if (mp.find(3)->second  > mp.find(2)->second) {
		for (int i = n - 1; i >= 0; i--) {
			int curr = s[i] - '0';
			if (curr == 1) continue;
			ans = (ans * 10) + curr;
		}
	} else {
		int sevens = 0;
		if (mp.find(7) != mp.end()) {
			sevens = mp.find(7)->second;
		}
		forn(i, sevens) {
			ans = (ans * 10) + 7;
		}

		int fives = 0;
		if (mp.find(5)  != mp.end()) {
			fives = mp.find(5)->second;
		}

		forn(i, fives) {
			ans = (ans * 10) + 5;
		}

		int threes = 0;
		if (mp.find(3) != mp.end()) {
			threes = mp.find(3)->second;
		}


		mp[2] -= threes;
		forn(i, threes) {
			ans = (ans * 10) + 3;
		}

		int twos = mp.find(2)->second;
		forn(i, twos) {
			ans = (ans * 10) + 2;
		}

	}

	cout << ans << "\n";



	return 0;
}
