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

int A() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, x, t; cin >> n >> x >> t;
	int ans = ((n + x - 1) / x) * t;
	cout << ans << "\n";
	return 0;
}

int B() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	ll sm = 0;
	cin >> s;
	forn(i, s.length()) {
		int c = s[i] - '0';
		sm += c;
	}
	if (sm % 9 == 0) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}

int C() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n; cin >> n;
	vi a(n);
	forn(i, n) cin >> a[i];
	ll ans = 0;
	REP(i, 1, n - 1) {
		if (a[i - 1] > a[i]) {
			ans += a[i - 1] - a[i];
			a[i] = a[i - 1];
		}
	}
	cout << ans << "\n";
	return 0;
}

//Previously Nice DP solution does not work because of BFS possib
int D() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h, w, ch, cw, dh, dw;
	cin >> h >> w >> ch >> cw >> dh >> dw;
	vector<string> s(h + 1);
	REP(i, 1, h) {
		cin >> s[i];
	}
	queue<tuple<int, int, int> >  q;
	tuple<int, int, int> tup = make_tuple(ch, cw, 0);
	vector<vector<int> > res(h + 1, vector<int>(w + 1, INF));
	q.push(tup);
	int mov[4][2] = { { -1, 0}, {1, 0}, {0, -1}, {0, 1}};
	while (!q.empty()) {
		tuple<int, int, int> curr = q.front(); q.pop();
		int row, col, val = 0;
		tie(row, col, val) = curr;
		cout << "this is front :" << row << " " << col << "\n";

		if (val < res[row][col]) {
			res[row][col] = val;
			forn(i, 4) {
				int nr = row + mov[i][0];
				int nc = col + mov[i][1];
				cout << i << "i is \n";
				cout << nr << " nc " << nc << " " << s[nr - 1][nc - 1] <<  "\n";
				if (nr < 1 || nc < 1 || nr > h || nc  > w || s[nr - 1][nc - 1] == '#') continue;
				cout << nr << " got nc " << nc << "\n";
				if (val < res[nr][nc]) {
					res[nr][nc] = val;
					q.push(make_tuple(nr, nc, val));
				}

			}
			//	}



			// REP(p, row - 2, row + 2) {
			// 	REP(r, col - 2, col + 2) {
			// 		if (p < 1 || r < 1 || p > h || r  > w || s[p - 1][r - 1] == '#') continue;
			// 		cout << "here but : " << res[p][r] << "\n";
			// 		if (res[row][col] + 1 < res[p][r]) {
			// 			res[p][r] = res[row][col] + 1;
			// 			cout << p << " p fives" << r << "\n";
			// 			q.push(make_tuple(p, r, res[row][col] + 1));
			// 		}

			// 	}
			// }
		}

		REP(i, 1, h) {
			REP(j, 1, w) {
				cout << res[i][j] << " ";
			}
			cout << "\n";
		}
		if (res[dh][dw] == INF) {
			cout << - 1 << "\n";
		} else {
			cout << res[dh][dw] << "\n";
		}
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h, w, m; cin >> h >> w >> m;
	vector<vector<int> > bombs(h + 1, vector<int>(w + 1, 0));
	forn(i, m) {
		int hi, wi; cin >> hi >> wi;
		bombs[hi][wi] = 1;
	}
	vector<int> rows(h + 1, 0);
	vector<int> cols(w + 1, 0);
	REP(i, 1, h) {
		REP(j, 1, w) {
			if (bombs[i][j] == 1) {
				// cout << "bomb here" << i << " " << j << "\n";
				rows[i]++;
				cols[j]++;
			}
		}
	}
	int ans = 0;
	REP(i, 1, h) {
		REP(j, 1, w) {
			if (bombs[i][j] && (rows[i] + cols[j]) - 1 > ans) {
				// cout << "first " << "\n";
				ans = (cols[j] + rows[i]) - 1;
			} else if (!bombs[i][j] && rows[i] + cols[j] > ans) {
				// cout << "second" << i << j <<"\n";
				ans = rows[i] + cols[j];
			}
		}
	}
	cout << ans << "\n";
	return 0;
}

