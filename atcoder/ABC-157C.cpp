#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	map<int, int> mp;
	bool poss = true;
	vector<pair<int, int> >  vp;
	for (int i = 0; i < m; i++) {
		int s, c;
		cin >> s >> c;
		if (mp.find(s) != mp.end()) {
			auto it = mp.find(s);
			if (it->second != c) {
				poss = false;
			}
		} else {
			if (s == 1 && c == 0 && n > 1) {
				poss = false;
			}
			mp[s] = c;
			vp.push_back(make_pair(s, c));
		}
	}

	if (poss && vp.size() <= n) {
		sort(vp.begin(), vp.end());
		int j = 0;
		string ans = string(n, '1');
		for (int i = 1; i <= n; i++) {
			if (j < vp.size() && vp[j].first ==  i) {
				char c = (char) vp[j].second + '0';
				ans[i - 1] = c;
				j++;
			} else {
				if (i == 1 && i < n) {
					ans[i - 1] = '1';
				} else {
					ans[i - 1] = '0';
				}
			}
		}
		cout << ans << "\n";

	} else {
		cout << -1 << "\n";
	}


}