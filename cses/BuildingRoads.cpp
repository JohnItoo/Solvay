#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > roads;
int mx = 1e5 + 7;
vector<bool> visited(mx, false);
vector<vector<int> > graph(mx);
vector<int> clusters;

void dfs(int curr) {
	if (visited[curr]) continue;
	visited[curr] = true;

	for (int child : graph[curr]) {
		dfs(child);
	}
}

int main() {
	int n, m; cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int p, q; cin >> p >> q;
		graph[p].push_back(q);
		graph[q].push_back(p);
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		dfs(i);
		clusters.push_back(i);
	}
	cout << clusters.size() - 1 << "\n";
	for (int i = 1; i < clusters.size(); i++) {
		cout << clusters[i - 1] << " " << clusters[i] << "\n";
	}
}