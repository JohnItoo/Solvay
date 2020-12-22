#include <bits/stdc++.h>
using namespace std;
#define _CRT_SECURE_NO_DEPRECATE

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

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
	int tc; cin >> tc;
	while (tc--) {
		string n; int s; cin >> n >> s;
		int q = 0;
		int last = -1;

		forn(i, n.length()) {
			q += (n[i] - '0');
			if (last == i - 1 && q + 1 <= s) last++;
		}
		if (q <= s) {
			cout << 0 << endl;
		} else {
			int len = n.length();
			ll have = stoll(n);

			if (last == -1) {
				ll need = pow(10, len);
				cout << need - have << endl;
			} else {
				ll pref = stoll(n.substr(0, last + 1));
				ll suff = pow(10, (len - last - 1));
				pref +=1;
				pref *= suff;
				cout << pref - have << endl;
			}
		}
	}
	return 0;
}
