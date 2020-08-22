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
int main() {
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
		if (val < res[row][col]) {
			res[row][col] = val;

			forn(i, 4) {
				int nr = row + mov[i][0];
				int nc = col + mov[i][1];
				if (nr < 1 || nc < 1 || nr > h || nc  > w || s[nr][nc] == '#') continue;
				res[nr][nc] = val;
				cout << nr << " nc " << nc << "\n";
				q.push(make_tuple(nr, nc, val));
			}
			REP(p, row - 2, row + 2) {
				REP(r, col - 2, col + 2) {
					if (p < 1 || r < 1 || p > h || r  > w || s[p][r] == '#') continue;
					if (val + 1 < res[p][r]) {
						res[p][r] = val + 1;
						cout << p << " p " << r << "\n";
						q.push(make_tuple(p, r, val + 1));
					}

				}
			}

		}
	}
	if (res[dh][dw] == INF) {
		cout << - 1 << "\n";
	} else {
		cout << res[dh][dw] << "\n";
	}

	return 0;
}

