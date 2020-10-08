#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;
	map<int, int> mp;
	vector<int> va;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (mp.find(x) == mp.end() && va.size() == 3) {
			cout << "NO\n";
			return 0;
		}
		if (mp.find(x) == mp.end()) {
			va.push_back(x);
			mp[x] = 1;
		}
	}

	if (va.size() == 1) {
		cout << "NO\n";
	} else if(va.size() == 2) {
		if(va[0] % 2 == va[1] % 2) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}else {
		sort(va.begin(), va.end());

		if (va[1] - va[0] == va[2] - va[1]) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}