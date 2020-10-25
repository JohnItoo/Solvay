#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);
	int x, y, m;
	cin >> x >> y >> m;
	int n = m / x;
	int ans = 0;
	int bg = m/y;
	ans = bg * y;
	for (int i = 0; i <= n; i++) {
		int small = i;
		int big = n - small;
		int curr = (small * x) + (big * y);
		if (curr <= m) ans = max(ans, curr);
	}
	cout << ans << "\n";

	return 0;
}