#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<int, int> mp;

	int ans = 0;
	int curr = 0;
	int last = 0;
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		auto it = mp.find(k);
		if (it != mp.end() && it->second >= last) {
			curr = i - it->second;
			last = it->second + 1;
			if (curr == 1) mp.clear();
			mp[k] = i;
			// cout << curr <<  "reset\n";

		} else {
			curr++;
			mp[k] = i;
			// cout << curr << " inc\n";
		}
		ans = max(ans, curr);
	}
	cout << ans << "\n";
}