#include <bits/stdc++.h>
using namespace std;

#define ll long long

int firs() {
	int n; cin >> n;
	ll x; cin >> x;
	vector<pair<ll, int> > v;
	map<ll, int> mp;
	for (int i = 0; i < n; ++i) {
		ll y;
		cin >> y;
		v.push_back(make_pair(y, i));
		mp[y]++;
	}
	sort(v.begin(), v.end());
	bool has = false;
	int firs = 0;
	int firsV = -1;
	for (int i = 0; i < n; i++) {
		auto it = mp.find(x - v[i].first);
		if (mp.find(x - v[i].first) != mp.end()) {
			if (x % 2 == 0 && v[i].first == x / 2) {
				if (it->second >= 2) {
					firs = v[i].second;
					has = true;
					firsV = v[i].first;
				}
			} else {
				firs = v[i].second;
				firsV = v[i].first;
				has = true;
			}
		}

		if (has) break;
	}

	if (!has) {
		cout << "IMPOSSIBLE" << "\n";
	} else {
		pair<ll, int> dis = make_pair(x - firsV, 0);
		auto it = lower_bound(v.begin(), v.end(),  dis);

		pair<ll, int> diff = *it;
		// cout << diff.second << " " << firs << "\n";
		if (diff.second == firs) ++it;
		diff = *it;

		cout << firs + 1 << " " << diff.second + 1 << "\n";
	}


	return 0;
}

int main() {
	int n; cin >> n;
	int x; cin >> x;
	map<int, int> mp;

	for (int i = 0; i < n; i++) {
		int q;
		cin >> q;
		if (mp.find(x - q) != mp.end()) {
			cout << mp[x - q] + 1 << " " << i + 1 << "\n";
			return 0;
		} else {
			mp[q] = i;
		}
	}
	cout << "IMPOSSIBLE\n";
}