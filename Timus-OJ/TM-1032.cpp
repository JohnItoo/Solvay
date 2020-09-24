#include <bits/stdc++.h>
using namespace std;

#define ll long long

//pigeon hole principle check lemma.

int main () {
	int n; cin >> n;
	vector<ll> pref(n + 1, 0);
	vector<ll> a(n + 1, 0);

	int left = 0;
	int right = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pref[i] = a[i] + pref[i - 1];
		if (pref[i] % n == 0)  {
			right = i;
		}
	}
	map<int, int> mp;

	if (right == 0) {
		for (int i = 1; i <= n; i++) {
			int mod = pref[i] % n;
			if (mp.find(mod) != mp.end()) {
				right = i;
				left = mp[mod];
				break;
			} else {
				mp[mod] = i;
			}
		}

	}

	cout << right - left << "\n";
	for (int i = left + 1; i <= right; i++) {
		cout << a[i] << "\n";
	}

	return 0;
}