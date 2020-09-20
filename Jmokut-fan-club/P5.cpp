#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int> > dp(n + 5, vector<int>(n + 5, 0));

    dp[0][0] = 1;
    for (int i = 2; i <= n; i++) { //bricks
        for (int j = 1; j < i; j++) {
            dp[i][j] = dp[i][j - 1];

            if (i >= j) {

            }
        }
    }
    cout << dp[n][n] << "\n";

    return 0;
}