#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	multiset<int> tickets;
	map<int, int> done;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		tickets.insert(x);
		done[x]++;
	}
	for (int i = 0; i < m; i++) {
		int p; cin >> p;
		auto it = tickets.lower_bound(p);
		if (*it > p) --it;
		int ans = -1;
		if (it != tickets.begin()) ans = *it;
		cout << ans << " ";
		tickets.erase(it);

	}


}