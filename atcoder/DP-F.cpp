#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    vector<vector<int> > dp(n + 5, vector<int>(m + 5, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int last = 0;
    string ans = "";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] > last) {
                last = dp[i][j];
                ans.push_back(s[i - 1]);
            }
        }
    }
    cout << ans << endl;

    return 0;
}