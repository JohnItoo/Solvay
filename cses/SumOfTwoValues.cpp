#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int n; cin >> n;
	ll x; cin >> x;
	vector<ll> v;
	map<ll, int> mp;
	for (int i = 0; i < n; ++i) {
		ll y;
		cin >> y;
		v.push_back(y);
		mp[y]++;
	}
	bool has = false;
	int firs = -1;
	for (int i = 0; i < n; i++) {
		auto it = mp.find(x - v[i]);
		if (mp.find(x - v[i]) != mp.end()) {
			if (x % 2 == 0 && v[i] == x / 2) {
				if (it->second >= 2) {
					firs = i;
					has = true;
				}
			} else {
				has = true;
			}
		}

		if (has) break;
	}


}