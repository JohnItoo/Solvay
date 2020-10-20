#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m; cin >> n >> m;
	vector<long long> a(n);
	vector<long long> prefs(n);
	long long prev = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		prev += a[i];
		prefs[i] = prev;
	}

	for (int i = 0; i < m; i++) {
		long long x; cin >> x; 
		auto it = lower_bound(prefs.begin(), prefs.end(), x);
		int diff = it - prefs.begin();
		if (diff == 0) {
			cout << 1 << " " << x << "\n";
		} else {
			long long p = prefs[diff - 1];
			cout <<  diff + 1 << " " << x - p << "\n";
		}

	}


	return 0;
}