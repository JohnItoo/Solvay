#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int n; cin >> n;
	int MX = 1e9 + 8;
	vector<int> h(n);
	for (int i = 0; i < n; i++) cin >> h[i];
	vector<ll> dp(n , MX);
	dp[0] = 0;
	dp[1] = abs(h[1] - h[0]);

	for (int i = 2; i <= n; i++) {
	   dp[i] = min((dp[i-1] + abs(h[i-1] - h[i])), dp[i-2] + abs(h[i-2]- h[i]));
	}
	cout << dp[n-1] << "\n";


}