#include <bits/stdc++.h>

#include <unordered_map>
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
        int n, m;
        cin >> n >> m;
        vi a(n);
        vi b(n);
        vi c(m);
        forn(i, n) cin >> a[i];
        forn(i, n) cin >> b[i];
        forn(i, m) cin >> c[i];
        unordered_map<int, vi> desnot;
        unordered_map<int, int> dessame;
        forn(i, n) {
            if (a[i] == b[i]) {
                if (!dessame.count(b[i])) dessame[a[i]] = i + 1;
            } else {
                if (!desnot.count(b[i])) desnot[b[i]].pb(1);
                desnot[b[i]].pb(i + 1);
            }
        }
        vi result;  // if -1

        forn(i, m) {
            int pt = c[i];
            if (desnot.count(pt)) {
                vi stt = desnot[pt];

                int val = stt[stt[0]];
                result.pb(val);
                stt[0]++;
                if (stt[0] == stt.size()) {
                    if (!dessame.count(pt)) {
                        dessame[pt] = val;
                    }
                    desnot.erase(pt);
                } else
                    desnot[pt] = stt;
            } else if (dessame.count(pt)) {
                int opt = dessame[pt];
                result.pb(opt);
            } else {
                result.pb(-1);
            }
        }
        if (result[m - 1] == -1 || desnot.size() != 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            forn(i, m) {
                if (result[i] == -1)
                    cout << result[m - 1] << " ";
                else
                    cout << result[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}