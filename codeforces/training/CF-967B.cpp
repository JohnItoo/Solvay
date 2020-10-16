#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b; cin >> n >> a >> b;
	int fst; cin >> fst;
	vector<int> vi(n - 1, 0);
	long long sum = fst;
	for (int i = 0; i < n - 1; i++) {
		cin >> vi[i];
		sum += vi[i];
	}
	sort(vi.rbegin(), vi.rend());
	if (((fst * a) / sum) >= b) {
		cout << 0 << endl;
	} else {
		long long curr = sum;
		int ct = 0;
		for (int i = 0; i < n - 1; i++) {
			curr -= vi[i];
			ct++;
			if (((fst * a) / curr) >= b) {
				cout << ct << endl;
				return 0;

			}

		}
	}
	return 0;

}