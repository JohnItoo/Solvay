#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> weights(n);
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }
    vector<vector<long long int> > dp(n + 5, vector<long long int>(W + 5, 0));

    for (int i = 1; i <= n; i++) {
        for (int weight = 1; weight <= W; weight++) {
            dp[i][weight] = dp[i - 1][weight];
            if (weights[i - 1] > weight) continue;
            dp[i][weight] =
                max((long long int)(dp[i - 1][weight - weights[i - 1]]) + values[i - 1],
                    dp[i - 1][weight]);
        }
    }
   

    cout << dp[n][W] << endl;

    return 0;
}