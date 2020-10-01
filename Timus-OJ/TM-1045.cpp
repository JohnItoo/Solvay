#include <bits/stdc++.h>
using namespace std;

vector<int> g[1005];
pair<int, int> mp;

void dfs(int k, int parent,  int depth) {
	if (g[k].size() == 1) {
		if ((depth & 1) && parent < mp.second) {
			mp = make_pair(depth, parent);
		}
		return;
	}
	for (int e : g[k]) {
		int p = depth == 0 ? e : parent;
		dfs(e, p, depth + 1);
	}
}


int main() {
	mp = make_pair(10005, 10005);
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(k, k, 0);
	if (mp.first == 10005) {
		cout << "First player loses\n";
	} else {
		printf("First player wins flying to airport %d", mp.second);
	}

	return 0;
}