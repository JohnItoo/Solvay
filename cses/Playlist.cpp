#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<int, int> mp;

	int ans = 0;
	int curr = 0;
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		auto it = mp.find(k);
		if (it == mp.end()) {
			curr++;
			mp[k] = i;
		} else {
			curr = i - it->second;
			// mp.clear();
			mp[k] = i;

		}
		ans = max(ans, curr);
	}
	cout << ans << "\n";
}