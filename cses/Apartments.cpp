#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	long long k; cin >> k;
	vector<long long> a(n), b(m);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0 ; i < m; i++) {
		cin >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());


	int i = 0; int j = 0;
	int ans = 0;
	while (i < n && j < m) {
		long long left = a[i] - k;
		long long right = a[i] + k;
		if (right < b[j]) {
			i++;
		} else if (left > b[j]) {
			j++;
		} else {
			ans += 1;
			i++;
			j++;
		}
	}

	cout << ans << "\n";

}