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
    vector<vector<int> > dp(W + 5, vector<int>(n + 5, 0));

    for (int i = 1; i <= n; i++) {
        for (int weight = 1; weight <= W; weight++) {
            if (weights[i - 1] > weight) continue;
            cout << "here ";
            dp[weight][i] =
                max((dp[weight - weights[i - 1]][i - 1]) + values[i - 1],
                    dp[weight][i - 1]);
        }
    }
    for(int weight = 1; weight <= W; weight++) {
        for(int i = 1; i <= n; i++) {
            cout << dp[weight][i] << " ";
        }
        cout << endl;
    }
    cout << dp[W][n] << endl;

    return 0;
}