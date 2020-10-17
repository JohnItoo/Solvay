#include <bits/stdc++.h>
using namespace std;

int main() {

	set<int> st;
	map<int, int> freq;
	vector<int> vi;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (freq.find(x) == freq.end()) {
			vi.push_back(x);
		}
		freq[x]++;
		st.insert(x);
	}

	int len = vi.size();
	int ans = 0;

	for (int i = 0; i < len; i++) {
		int x = vi[i];

		for (int j = 0; j <= 5; j ++) {
			int l = j; int r = 5 - j;

			auto it = st.lower_bound(x - l);
			int ct = 0;

			while (it != st.end() && *it >= x - l && *it <= x + r) {
				ct += freq[*it];
				++it;
			}
			ans = max(ans, ct);

		}


	}


	cout << ans << "\n";

	return 0;
}