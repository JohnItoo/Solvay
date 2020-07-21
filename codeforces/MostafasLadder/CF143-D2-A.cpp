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
	int r1, r2, c1, c2, d1, d2;
	cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
	int x = min(c1, r2) - 1;
	int a = -1; int b = 0; int c = 0; int d = 0;
	for (int botlef = 9; botlef >= 1; botlef--) {
		int  botright = r2 - botlef;
		int  toplef = c1 - botlef;
		int toprt = r1 - toplef;

		if (botlef + toprt == d2 && toplef + botright == d1
		        && (toplef > 0 && toplef < 10) &&  (toprt > 0 && toprt < 10) &&
		        (botlef > 0 && botlef < 10) && (botright > 0 && botright < 10) )  {
			a = toplef;
			b = toprt;
			c = botlef;
			d = botright;
			break;
		}
	}
	if (a != -1 && (a != b && a != c && a != d) && (b != c && b != d) && c != d) {
		cout << a << " " << b << endl;
		cout << c << " " << d << endl;
	} else {
		cout << -1 << endl;
	}


	return 0;
}
