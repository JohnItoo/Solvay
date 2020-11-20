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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m; cin >> n >> m;
		vector<string> s(n);

		forn(i, n) cin >> s[i];
		vector<int> moves;

		for (int i = 0; i + 1 < n; i++) {
			for (int j = 0; j + 1 < m; j++) {
				int zeros = 0;
				int ones = 0;
				s[i][j] == '0' ? zeros++ : ones++;
				s[i][j + 1] == '0' ? zeros++ : ones++;
				s[i + 1][j] == '0' ? zeros++ : ones++;
				s[i + 1][j + 1] == '0' ? zeros++ : ones++;

				if (!ones || (ones == 1 && s[i + 1][j + 1] == '1')) {
					continue;
				}

				if (ones == 1) {

					for (int q = i; q < i + 2; q++) {
						for (int r = j; r < j + 2; r++) {
							if (q == i + 1 && r == j + 1) continue;
							moves.pb(q + 1); moves.pb(r + 1);

						}

					}

					for (int q = i; q < i + 2; q++) {
						for (int r = j; r < j + 2; r++) {
							if (s[q][r] == '1') { s[q][r] = '0'; continue;}
							moves.pb(q + 1); moves.pb(r + 1);
							if (q == i + 1 && r == j + 1) {
								s[q][r] = '1';

							}

						}

					}
				} else if (ones == 2) {
					int px = -1;
					int py = -1;


					for (int q = i; q < i + 2; q++) {
						for (int r = j; r < j + 2; r++) {
							if (s[q][r] == '1') {
								if (px != -1) continue;
								px = q;
								py = r;
							}
							moves.pb(q + 1); moves.pb(r + 1);

						}
					}

					for (int q = i; q < i + 2; q++) {
						for (int r = j; r < j + 2; r++) {
							if (s[q][r] == '1') {
								if (px == q && py == r) continue;
							}
							moves.pb(q + 1); moves.pb(r + 1);
						}
					}
					s[i][j] = '0';
					s[i + 1][j] = '0';
					s[i + 1][j + 1] = '0';
					s[i][j + 1] = '0';
				} else if (ones == 3) {
					for (int q = i; q < i + 2; q++) {
						for (int r = j; r < j + 2; r++) {
							if (s[q][r] == '1') {
								moves.pb(q + 1); moves.pb(r + 1);
								s[q][r] = '0';
							}

						}
					}
				} else {
					for (int q = i; q < i + 2; q++) {
						for (int r = j; r < j + 2; r++) {
							if (q == i + 1 && r == j + 1) continue;

							moves.pb(q + 1); moves.pb(r + 1);
							s[q][r] = '0';
						}
					}
				}

			}
		}
		int sz =  moves.size();
		cout << sz / 6 << endl;
		forn(i, sz/6) {
			forn(j, 6) {
				cout << moves[(i*6) + j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}

