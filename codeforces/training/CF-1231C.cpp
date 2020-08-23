#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int getLast(ll num) {
	return num % 10;
}

int main() {
	int q; cin >> q;
	while (q--) {
		ll n, m; cin >> n >> m;
		vector<int> trail;
		int lst = getLast(m);
		trail.push_back(lst);

		ll idx = 2;
		while (getLast(idx * lst) != lst) {
			int ths = getLast(idx * lst);
			idx++;
			trail.push_back(ths);
		}
		int k = trail.size();
		ll ans = 0;
		if (n > k) {
			ll sm = 0;
			for (int i = 0; i < k; i++) {
				sm += trail[i];
			}
			cout << sm << "\n";
			ll d = n / k;
			ll rem = n - (k * d);
			ll sumrem = 0;
			for (int i = 0; i < rem; i++) {
				sumrem += trail[i];
			}
			ans = (sm * d) + sumrem;

		} else {
			for (int i = 0; i < n; i++) {
				ans += trail[i];
			}
		}
		cout << ans << "\n";
	}
}