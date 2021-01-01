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
    while(tc--) {
        int n; cin >> n;
        vi a(n);
        forn(i, n) cin >> a[i];
        bool dec = n > 1;
        REP(i, 1, n) {
            if(n - (i-1) != a[i-1]) {
                dec = false;
                break;
            }
        }
        if(dec) {
           if(n&1) cout << 2 << endl;
           else cout << 1 << endl;
           continue;
        } else {
            int ans = 0;
           forn(i, n-1) {
               if(a[i] > a[i+1]) ans++;
           }
           cout << ans << endl;
        }
    }
	return 0;
}