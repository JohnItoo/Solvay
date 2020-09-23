#include <bits/stdc++.h>
using namespace std;

int main () {
	int n, m; cin >> n >> m;
	vector<int> dp(10005, 0);

	vector<int> k(m);
	for (int i = 0; i < m; i++) {
		cin >> k[i];
	}

	sort(k.begin(), k.end());
	int lst = k[0];
	for (int i = 1; i < n; i++) {
		lst |= k[i];
	}
	return 0;
}