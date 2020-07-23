#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long sum = (n * (n + 1)) / 2;
	if ((sum & 1) ) {
		cout << "NO\n";
	} else {
		vector<int> a;
		vector<int> b;
		long long s = sum / 2;
		int dp[s+1][n+1];
		memset(dp, 1000000, sizeof dp);
		dp[0][0] = 0;

		for(int i = 0; i <= s; i++) {
			for(int j = 1; j <= n; j++) {
				dp[i][j] = dp[i][j-1];
                if(j <= i) {
                	dp[i][j] = min(dp[i][j], dp[i-j][j-1]+1);
                }
			}
		}

		for(int i = 0; i <= s; i++) {
			for(int j = 0; j <= n; j++) {
				cout << dp[i][j] << " ";
			}
			cout << "\n";
		}

	}
}
