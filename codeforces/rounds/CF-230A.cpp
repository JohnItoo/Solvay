#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}


int main() {
	long long s, n; cin >> s >> n;
	vector<pair<int, int> > vd;

	for (int i  = 0; i < n; i++) {
		int x, y; cin >> x >> y;

		vd.push_back(make_pair(x, y));
	}
	sort(vd.begin(), vd.end(), compare);

	for (int i = 0; i < n; i++) {
		if (s <= vd[i].first) {
			cout << "NO\n";
			return 0;
		}
		s += vd[i].second;
	}
	cout << "YES\n";
	return 0;
}