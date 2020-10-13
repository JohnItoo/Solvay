#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;

vector<int> factors(int n) {
	vector<int> f;
	for (int x = 1; x * x <= n; x++) {
		if (n % x == 0) {
			f.push_back(x);
			if (x != n / x) {
				f.push_back(n / x);

			}
		}
	}
	return f;
}

int main() {
	int n; cin >> n;
	int m = n;
	vector<int> fc = factors(n);
	int ans = 0;
	while (m) {
		mp[m % 10]++;
		m /= 10;
	}
	for (auto fac : fc) {
		while (fac) {
			if (mp.find(fac % 10) != mp.end()) {
				ans++;
				break;
			}
			fac /= 10;
		}
	}
	cout << ans << "\n";
	return 0;
}