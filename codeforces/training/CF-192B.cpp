#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	int mx = 0;
	int M = 10e3 + 5;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}

	vector<int> dp(M, 0);

	dp[1] = a[0];

	if(n <= 1) {
		cout << dp[1];
		return 0;
	}
	dp[2] = min(a[0], a[1]);

   for(int i = 3; i <= n; i++) {
   	dp[i] = min(max(dp[i-1], dp[i-2]), a[i-1]);
   }

	cout << dp[n] << "\n";

	//f

	return 0;
}