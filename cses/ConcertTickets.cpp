#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	multiset<int> tickets;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		tickets.insert(x);
	}

	for (int i = 0; i < m; i++) {
		int p; cin >> p;
		if (tickets.size() > 0) {
			auto it = tickets.lower_bound(p);
			if (it == tickets.end() || *it > p) --it;

			int ans = -1;
			if (it != tickets.end() && *it <= p) {
				ans = *it;
				tickets.erase(it);
			}

			cout << ans << "\n";
		} else {
			cout << -1 << "\n";
		}

	}
}