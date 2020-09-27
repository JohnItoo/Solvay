#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	vector<long long> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	long long res = 0;
	long long curr = 0;

	for (int i = 1; i <= n; i++) {
		long long ds = a[i];
		long long prs = (ds + curr) / 2;
		res += prs;
		if (ds == 0) {
			curr =  0;
		} else {
			curr = (ds + curr) % 2;
		}
		// cout << prs << " pairs\n";
	}
	cout << res << "\n";
}