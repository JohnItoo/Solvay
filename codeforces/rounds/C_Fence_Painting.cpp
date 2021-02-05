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
        int n, m;
        cin >> n >> m;
        vi a(n);
        vi b(n);
        vi c(m);
        forn(i, n) cin >> a[i];
        forn(i, n) cin >> b[i];
        forn(i, m) cin >> c[i];
        map<int, set<int>> desnot;
        map<int, set<int>> dessame;
        forn(i, n) {
            if (a[i] == b[i])
                dessame[a[i]].insert(i);
            else
                desnot[a[i]].insert(i);
        }
        vi result(m, -1);  // if -1
        map<int, vi> paints;

        forn(i, m) {
            int pt = c[i];
            if (!desnot.count(pt) && !dessame.count(pt)) {
                continue;  // leave as =-1;
            }
            if (desnot.count(pt)) {
                set<int> stt = desnot[pt];
                auto it = stt.begin();
                int val = *it;
                result[i] = val;
                a[val - 1] = pt;
                stt.erase(it);
                if (stt.size() == 0)
                    desnot.erase(pt);
                else
                    desnot[pt] = stt;
            } else {
                set<int> ste = dessame[pt];
                auto it = ste.begin();
                int val = *it;
            }
        }
        if (result[m - 1] == -1) {
            cout << "NO\n";
        } else {
            forn(i, n) { if }
        }
    }
    return 0;
}