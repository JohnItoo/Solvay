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
    int n;
    cin >> n;

    vi arr(n);
    forn(i, n) { cin >> arr[i]; }
    vi loss(n);

    if (arr[0] == 3) {
        cout << "NO\n";
        return 0;
    }
    loss[0] = arr[0] == 1 ? 2 : 1;

    if (n >= 2) {
        if (arr[1] == 3) {
            loss[1] = arr[0];
        } else {
            if (arr[0] != arr[1]) {
                cout << "NO\n";
                return 0;
            }
            loss[1] = 3;
        }
    }

    REP(i, 2, n - 1) {
        if (arr[i] == arr[i - 1] || arr[i] == loss[i - 2]) {
            loss[i] = arr[i] == arr[i - 1] ? loss[i - 2] : arr[i - 1];
        } else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}
