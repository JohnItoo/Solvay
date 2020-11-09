#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("shell.in", "r", stdin);
	freopen("shell.out", "w", stdout);
	int n; cin >> n;
	vector<pair<pair<int, int>, int> > mv;
	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		mv.push_back(make_pair(make_pair(a, b), c));
	}

	int res = 0;

	for (int i = 1; i <= 3; i++) {
		int arr[3] = {0, 0, 0};
		arr[i - 1] = 1;
		int dz = 0;
		for (int j = 0; j < n; j++) {
			pair<pair<int, int>, int> curr = mv[j];
			int a = curr.first.first;
			int b = curr.first.second;
			int c = curr.second;

			swap(arr[a - 1], arr[b - 1]);

			if (arr[c - 1]) dz++;
		}
		res = max(res, dz);
	}
	cout << res << "\n";

	return 0;
}