#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);

	int n; cin >> n;
	vector<pair<int, pair<string, int> > > lst;
	for (int i = 0; i < n; i++) {
		int x; string y; int z;

		cin >> x >> y >> z;
		lst.push_back(make_pair(x, make_pair(y, z)));
	}
	sort(lst.begin(), lst.end());
	vector<int> arr(3, 7);
	map<int, int> curr;
	for (int i = 0; i < 3; i++) curr[i] = 1;

	int ans = 0;
	for (auto it : lst) {
		int x; string y; int z;
		x = it.first;
		y = it.second.first;
		z = it.second.second;

		if (y == "Bessie") {
			arr[0] += z;
		} else if (y == "Elsie") {
			arr[1] += z;
		} else {
			arr[2] += z;
		}
		int mx = *max_element(arr.begin(), arr.end());
		map<int, int> next;
		bool diff = false;
		for (int i = 0; i < 3; i++) {
			if (arr[i] == mx) {
				next[i] = 1;
			}
			if ((next.find(i) != next.end() && curr.find(i) == curr.end()) ||
			        (next.find(i) == next.end() && curr.find(i) != curr.end()) ) {
				diff = true;
			}
		}
		if (diff) ans++;
		curr = next;
	}
	cout << ans << "\n";

	return 0;
}