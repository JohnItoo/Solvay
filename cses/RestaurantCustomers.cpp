#include <bits/stdc++.h>
using namespace std;

int frist() {

	int n; cin >> n;
	set<pair<int, int> > st;
	int i = 0;
	while (i < n) {
		int x, y; cin >> x >> y;
		st.insert(make_pair(x, y));
		i++;
	}
	int ans = 0;
	int curr = 0;
	while (!st.empty()) {
		auto it = st.begin();
		pair<int, int> currPair = *it;
		auto fd = st.upper_bound(make_pair(currPair.second, currPair.second));
		curr++;
		st.erase(it);

		while (fd != st.end()) {
			pair<int, int> fdii = *fd;
			st.erase(fd);
			fd = st.upper_bound(make_pair(fdii.second, fdii.second));
		}
	}
	cout << curr << "\n";
}

int main() {
	int n; cin >> n;
	set<pair<int, int> > st;
	int i = 0;
	while (i < n) {
		int x , y; cin >> x >> y;
		st.insert(make_pair(x, 1));
		st.insert(make_pair(y + 1, -1));
		i++;
	}

	int ans = 0;
	int ent = 0;

	for (auto curr : st) {
		ent += curr.second;
		ans = max(ent, ans);
	}
	cout << ans << "\n";
}