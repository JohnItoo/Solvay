#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	multiset<int> tickets;
	map<int, int> done;
	int used = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		tickets.insert(x);
		done[x]++;
	}
	int last = 0;
	for (int i = 0; i < m; i++) {
		int p; cin >> p;

		if (tickets.size() >= 1) {
			auto it = tickets.lower_bound(p);
			if (*it > p && it != tickets.begin()) --it;

			int ans = -1;
			// cout << *it << " it \n";
			if (*it <= p) {
				ans = *it;
				tickets.erase(it);
				used++;
				last = i;
			}
			// tickets.erase(it);

			cout << ans << "\n";
			if (used == n) break;

		} else {
			cout << -1 << "\n";
		}


	}

	// for (int i = last + 1; i < m; i++) {
	// 	cout << -1 << "\n";
	// }


}