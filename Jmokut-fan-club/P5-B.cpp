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

    for (int bricks = 2; bricks <= n; bricks++) {
        for (int previous = 1; previous <= n; previous++) {
            for (int next = previous + 1; next <= n - previous; next++) {
                dp[bricks][previous] += dp[bricks + next][next];
            }
        }
    }
    return 0;
}