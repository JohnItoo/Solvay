#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	freopen("photo.in", "r", stdin);
	freopen("photo.out", "w", stdout);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n - 1; i++) cin  >> a[i];

	int last = 0;
	vector<int> ans;
	bool sub = true;
	int minmax = 1e9 + 8;

	vector<int> res;

	for (int i = 0; i < n - 1; i++)  {
		int diff = abs(last - a[i]);
		last = diff;
		if (sub) {
			minmax = min(diff, minmax);
			sub = false;
			diff = -diff;
		} else {
			sub = true;
		}
		res.push_back(diff);
	}

	int ao = minmax - 1;

	cout << ao << " ";
	for (int i = 0; i < res.size(); i++) {
		int x = res[i];
		if (x < 0) {
			cout << abs(x) - ao;
		} else {
			cout << x + ao;

		}
		if (i != res.size() - 1) {
			cout << " ";
		}
	}

	return 0;
}