
#include <bits/stdc++.h>
using namespace std;
#define _CRT_SECURE_NO_DEPRECATE
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
// To simplify repetitions/loops, Note: define your loop style and stick with
// it!
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
    vector<vector<int> > inp(n, vector<int>(3));
    forn(i, n) { cin >> inp[i][0] >> inp[i][1] >> inp[i][2]; }
    vector<vector<int> > dp(n + 5, vector<int>(3));
    dp[1][1] = inp[0][1];
    dp[1][0] = inp[0][0];
    dp[1][2] = inp[0][2];

    for (int i = 2; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + inp[i - 1][0];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + inp[i - 1][1];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + inp[i - 1][2];
    }
    cout << max(max(dp[n][0], dp[n][1]), dp[n][2]) << endl;
    return 0;
}
