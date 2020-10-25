#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);
	int x, y, m;
	cin >> x >> y >> m;
	int ans = 0;

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < m; j++) {
			int curr = (x*i) + (y*j);
			if( curr>m) break;
			ans = max(ans, curr);
		}
	}

	cout << ans << "\n";

	return 0;
}