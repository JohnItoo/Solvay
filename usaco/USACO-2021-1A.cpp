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

	vector<ll> arr(7);
	map<ll, int> freq;
	forn(i, 7) {
		cin >> arr[i];
		freq[arr[i]]++;
	}
	forn(i, 7) {
		REP(j, i + 1, 6) {
			REP(k, j + 1, 6) {
				if (i == j || i == k || j == k) continue;
				map<ll, int> dz = freq;
				dz[arr[i]]--;
				dz[arr[j]]--;
				dz[arr[k]]--;

				ll a = arr[i]; ll b = arr[j]; ll c = arr[k];
				if (dz.find(a + b + c) == dz.end()) {
					continue;
				}
				dz[a + b + c]--;
				if (dz.find(a + b) == dz.end()) {
					continue;
				}
				dz[a + b]--;

				if (dz.find(b + c) == dz.end()) {
					continue;
				}
				dz[b + c]--;

				if (dz.find(a + c) == dz.end()) {
					continue;
				}
				ll res[3] = {a, b, c};
				sort(res, res + 3);

				cout << res[0] << " " << res[1] << " " << res[2] << endl;
				return 0;
			}

		}
	}

	return 0;
}
