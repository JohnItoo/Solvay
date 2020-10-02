#include <bits/stdc++.h>
using namespace std;

vector<int> g[1005];
pair<int, int> mp;
vector<bool> visited(1005, false);
set<int> pots;
map<int, int> dels;

void dfs(int k, int parent,  int depth) {
	if (visited[k]) return;

	visited[k] = true;

	int ct = g[k].size();
	for (int e : g[k]) {
		if (visited[e]) ct--;
	}
	if (ct == 0) {
		if ((depth & 1)) {
			if (dels.find(parent) == dels.end()) {
				pots.insert(parent);

			}
		} else {
			cout << "here : " << depth << "\n";
			int p = depth == 0 ? k : parent;


			for (auto xx : pots) {
				cout << xx << " pots\n";
			}
			dels[p] = 1;

			auto it = pots.lower_bound(p);
			cout << *it << " it \n";
			if (it != pots.end() && *it == p) {
				cout << "ersase\n";
				pots.erase(it);
			}
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
	if (pots.size() == 0) {
		cout << "First player loses\n";
	} else {
		int gp = *pots.begin();
		printf("First player wins flying to airport %d\n", gp);
	}

	return 0;
}

