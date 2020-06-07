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
	char grid[4][4];
	forn(i, 4) {
		string s; cin >> s;
		forn(j, 4) {
			grid[i][j] = s[j];
		}
	}
	int dir[3][2] = { {0, 1}, {1, 0} , {1, 1}};
	string ans = "NO";
	forn(i, 3) {
		forn(j, 3) {
			int b = 0; int c = 0;
			if (grid[i][j] == '#') b++;
			else c++;
			for (int k = 0; k < 3; k++) {
				int nr = i + dir[k][0];
				int nc = j + dir[k][1];
				if (grid[nr][nc] == '#') b++;
				else c++;
			}
			if ((b == 0 && c == 4 ) || ( b == 1 && c == 3) || (c == 0  && b  == 4) || (c == 1 && b == 3)) {
				ans = "YES";
				break;
			}
		}
		if (ans == "YES") break;
	}
	cout << ans << endl;

	return 0;
}
