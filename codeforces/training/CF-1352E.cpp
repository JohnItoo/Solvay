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
    for (int i = int(a); i <= int(b); i++)  // a to b, and variable i is local!
#define forn(i, n) for (int i = 0; i < (n); i++)
#define TRvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000  // 2 billion
// If you need to recall how to use memset:
#define MEMSET_INF 127      // about 2B
#define MEMSET_HALF_INF 63  // about 1B
// memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path
// distances memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP
// memoization table memset(arr, 0, sizeof arr); // useful to clear array of
// integers

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        map<int, int> a;
        map<int, int> pref;
        int last = 0;
        forn(i, n) {
            int x;
            cin >> x;
            a[x]++;
            last += x;
            pref[last]++;
        }
        int ans = 0;
        for (auto it : a) {
            int x = it.first;
            int y = it.second;
            bool special = pref.find(x) != pref.end();

            for (auto jt : pref) {
                if (special) break;
                int fr = jt.first;
                int needone = fr - x;
                int needtwo = fr + x;
                if (pref.find(needone) != pref.end() ||
                    pref.find(needtwo) != pref.end()) {
                    cout << x << " " << needone << " " << needtwo << " " << fr
                         << endl;
                    special = true;
                    ans += y;
                    break;
                }
            }
            if (special) {
                cout << x << " " << y << endl;
                ans += y;
                continue;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
