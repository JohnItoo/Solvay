#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("cowqueue.in", "r", stdin);
	freopen("cowqueue.out", "w", stdout);
	int n; cin >> n;
	vector<pair<int, int> > vii;
	for(int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		vii.push_back(make_pair(x, y));
	}
	sort(vii.begin(), vii.end());
	int curr = 0;
	for(auto ii : vii) {
		curr = max(ii.first, curr) + ii.second;
	}
	cout << curr << "\n";


	return 0;
}