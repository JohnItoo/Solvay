#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	freopen("photo.in", "r", stdin);
	freopen("photo.out", "w", stdout);
	int n; cin >> n;
	vector<int> a(n - 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> a[i];
	}

	vector<int> res(n);
	for (int i = 1; i <= n; i++) {
		res[i - 1] = i;
	}

	vector<int> ans;

	do {
		bool invalid = false;
		for (int i = 0; i < n - 1; i++) {
			if (res[i] + res[i + 1] != a[i]) {
				invalid = true;
				break;
			}
		}
		if (!invalid) {
			if (ans.size() == 0) {
				ans = res;
			} else {
				for (int i = 0; i < n; i++) {
					if (ans[i] > res[i]) {
						ans = res;
						break;
					}
				}
			}

		}

	} while (next_permutation(res.begin(), res.end()));

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if(i != ans.size()-1) {
			cout << " ";
		}
	}

	return 0;
}