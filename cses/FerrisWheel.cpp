#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	set<pair<long long, int> > st;
	for (int i = 0; i < n; i++) {
		long long curr = 0; cin >> curr;
		st.insert(make_pair(curr, i));
	}

	int ans = 0;
	while (!st.empty()) {
		pair<long long , int> c = *st.begin();
		pair<long long , int> need = make_pair(x - c.first, c.second);
		auto it = st.upper_bound(need);
		if (it == st.end()) --it;
		while (it != st.begin()) {

			pair<long long , int> d = *it;
			if (d.first + c.first > x) --it;
			else break;
		}
		if (it != st.begin() && it != st.end()) {
			st.erase(it);
		}
		st.erase(st.begin());
		ans++;
	}
	cout << ans << "\n";

}