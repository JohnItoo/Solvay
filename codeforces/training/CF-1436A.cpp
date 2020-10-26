#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n, m; cin >> n >> m;
		vector<int> a(n);
		int sm = 0;
		for(int i = 0; i < n; i++) {
			int x; cin >> x;
			sm += x;
		}
		if (sm == m) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}