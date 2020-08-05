#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

int main() {
	int n;  cin >> n;
	long long ans = 1;
	for(int i = 1; i <= n; i++) {
		ans = i * ans;
		ans %= mod;
	}
	cout << ans << "\n";
}