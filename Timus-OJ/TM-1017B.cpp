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

    for (int sum = 2; sum <= n; sum++) {
        for (int endheight = 1; endheight <= n; endheight++) {
            for (int prevsum = 1;  prevsum + endheight <= n ; prevsum++) {
                dp[sum][endheight] += dp[prevsum][endheight];
            }
        }
    }
    cout << dp[n][n - 1] << endl;
    return 0;
}