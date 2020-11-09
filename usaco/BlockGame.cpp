#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);
	int n; cin >> n;
	vector<int> a(26, 0);
	for (int i = 0; i < n; i++) {
		string x, y; cin >> x >> y;
		vector<int> left(26, 0); vector<int> right(26, 0);
		for (int j = 0; j < x.length(); j++ ) {
			left[x[j] - 'a']++;
		}
		for (int j = 0; j < y.length(); j++) {
			right[y[j] - 'a']++;
		}

		for (int j = 0; j < 26; j++) {
			a[j] += max(left[j], right[j]);
		}
	}
	for (int i = 0; i < 26; i++) cout << a[i] << "\n";

	return 0;
}