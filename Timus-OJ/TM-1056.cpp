#include <bits/stdc++.h>
using namespace std;

set<int> result;
map<int, int> mp;


void dfs(vector<vector<int> > gp, int curr, int prev, vector<bool> visited) {
	if (visited[curr]) return;
	visited[curr] = true;
	if (mp[curr] == 1) {
		result.insert(prev);
		return;
	}

	for (int child : gp[curr]) {
		dfs(gp, child, curr, visited);
	}
}

int main() {
	int n; cin >> n;
	vector<vector<int> > gp(n + 1);
	for (int i  = 2; i <= n; i++) {
		int x; cin >> x;
		if (x == i) continue;
		gp[x].push_back(i);
		gp[i].push_back(x);
		mp[x]++;
		mp[i]++;
	}
	vector<bool> visited(n + 1, false);
	dfs(gp, 1, 0, visited);
	for (int res : result) {
		cout << res << " ";
	}
	return 0;
}