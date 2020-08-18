// https://codeforces.com/problemset/problem/804/A

#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	set<pair<int, int> > st;

	for (int i = 0; i < n; i++) {
		int dist = (((a[i] + 10) / 10)) * 10 - a[i];
		st.insert(make_pair(min(dist, 100 - a[i]), i));
	}
	for (int i = 0; i < k; i++) {

	}

	int i = 0;
	while (i < k && st.size() != 0) {
		auto it = st.begin();
		pair<int, int> curr = *it;
		if (k - i < curr.first) break;
		i += curr.first;
		a[curr.second] += curr.first;
		st.erase(it);
		int dist = 10;
		pair<int, int> nw = make_pair(dist, curr.second);
		if (a[curr.second] < 100) st.insert(nw);
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		ans += a[i] / 10;

	}

	cout << ans << "\n";





	return 0;
}