#include <bits/stdc++.h>
using namespace std;

vector<int> g[1005];
pair<int, int> mp;
vector<bool> visited(1005, false);

void dfs(int k, int parent,  int depth) {
	if (visited[k]) return;

	visited[k] = true;

	int ct = g[k].size();
	for (int e : g[k]) {
		if (visited[e]) ct--;
	}
	if (ct == 0) {
		if ((depth & 1) && parent < mp.second) {
			mp = make_pair(depth, parent);
		}

	} else {
		for (int e : g[k]) {
			if (!visited[e]) {
				int p = depth == 0 ? e : parent;
				dfs(e, p, depth + 1);
			}
		}
	}
}


int main() {
	mp = make_pair(10005, 10005);
	int n, k; cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int x, y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(k, k, 0);
	if (mp.first == 10005) {
		cout << "First player loses\n";
	} else {
		printf("First player wins flying to airport %d\n", mp.second);
	}

	return 0;
}

