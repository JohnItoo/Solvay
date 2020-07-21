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
#include <cmath>
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

int euclideanDistSQ(ii a, ii b) {
	return (pow(a.first - b.first, 2) + pow(a.second - b.second, 2) );
}

int main() {
	int n, m, x; cin >> n >> m >> x;
	map<char, vii> dict;
	vii shifts;
	forn(i, n) {
		string s; cin >> s;
		forn(j, m) {
			if (s[j] == 'S') shifts.pb(mp(i, j));
			else {
				if (dict.find(s[j]) == dict.end()) {
					vii xxx;
					xxx.pb(mp(i, j));
					dict[s[j]] = xxx;
				} else {
					dict.find(s[j])->second.pb(mp(i, j));
				}

			}
		}
	}
	int txt; cin >> txt;
	string s; cin >> s;
	int ans = 0;
	map<char, int> fd;
	forn(i, txt) {
		char curr = s[i];
		if (curr >= 'A' && curr <= 'Z') {
			auto it = fd.find(curr);
			if (it != fd.end()) {
				ans += it->second;
				continue;
			}
			bool can = false;
			bool without = false;
			string gg = to_string(curr);
			transform(gg.begin(), gg.end(), gg.begin(), ::tolower);
			char nw = (curr + 32);
			if (dict.find(nw) == dict.end()) {
				ans = -1;
				break;
			}
			vii xxx = dict.find(nw)->second;

			for (ii xx : xxx) {
				for (auto shift : shifts) {
					can = true;
					if (euclideanDistSQ(xx, shift) > pow(x, 2)) continue;
					without = true;
					break;
				}
				if (without) break;
			}

			if (can) {
				if (!without) {
					ans++;
					fd[curr] = 1;
				} else {
					fd[curr] = 0;
				}

			} else {
				ans = -1;
				break;
			}
		}  else {
			if (dict.find(curr) != dict.end()) continue;
			ans = -1;
			break;
		}
	}

	cout << ans << endl;

	return 0;
}
