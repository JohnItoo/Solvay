#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> x(n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		sum += x[i];
	}
	bool dp[sum + 1][n + 1];

	memset(dp, 0, sizeof dp);

	dp[0][0] = true;

	for (int i = 0; i <= sum; i++) {
		for (int j = 1;  j <= n; j++) {
			int val = x[j - 1];

			dp[i][j] |= dp[i][j - 1];
			if (val <= i) {
				dp[i][j]  |= dp[i - val][j - 1];

			}

		}
	}

	vector<int> fd;
	for (int i = 1; i <= sum; i++) {
		bool isFound = false;
		for (int j = 1; j <= n; j++) {
			if (dp[i][j]) {
				isFound = true;
				break;
			}
		}
		if (isFound) {
			fd.push_back(i);
		}
	}

	cout << fd.size() << "\n";

	for (int i = 0; i < fd.size(); i++) {
		cout << fd[i] << " ";
	}

}