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
int a[40005][40005];

string trUpp(string s) {

	transform(s.begin(), s.end(), s.begin(), ::toupper);
	return "";
}

int main() {
	int n, m, k, t; cin >> n >> m >> k >> t;
	map<string, int> wastes;
	forn(i, k) {
		int a, b; cin >> a >> b;
		wastes[to_string(a) + "+" + to_string(b)] = 1;
	}
	int lastFruit = 1;
	REP(i, 1, n) {
		REP(j, 1, m) {
			string xx = to_string(i) + "+" + to_string(j);
			if (wastes.find(xx) != wastes.end()) {
				a[i][j] = -1;
			} else {
				a[i][j] = lastFruit;
				if (lastFruit == 1) lastFruit = 2;
				else if (lastFruit == 2) lastFruit = 3;
				else lastFruit = 1;
			}

		}
	}


	forn(i, t) {
		int x; int y; cin >> x >> y;
		if (a[x][y] == -1) cout << "Waste" << endl;
		else if (a[x][y] == 1) cout << "Carrots" << endl;
		else if (a[x][y] == 2) cout << "Kiwis" << endl;
		else cout << "Grapes" << endl;
	}

	return 0;
}
