#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n; cin >> n;
    vector<vector<ll> > dp(n + 5, vector<ll>(n + 5, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        dp[0][i] = dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) { //bricks
        for (int j = 1; j <= n - 1; j++) { // last height
            dp[i][j] = dp[i][j - 1];

            if (i >= j) {
                dp[i][j] += dp[i - j][j - 1];
            }
        }
    }
    cout << dp[n][n - 1] << "\n";

    return 0;
}