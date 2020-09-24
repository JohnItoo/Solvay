#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main () {
	int n; cin >> n;
	// vector<ll> pref(n + 1);
	ll pref[n + 1];
	ll a[n + 1];
	// vector<ll> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pref[i] = a[i] + pref[i - 1];

	}
	bool ans = false;
	int left = 0; int right = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == j) continue;
			if (abs(pref[i] - pref[j]) % n == 0 ) {
				ans = true;
				left = i;
				right = j;
				break;

			}
		}
		if (ans) break;
	}
	if (left > right) swap(left, right);
	cout << right - left << "\n";
	for (int i = left + 1; i <= right; i++) {
		cout << a[i] << "\n";
	}

	return 0;
}