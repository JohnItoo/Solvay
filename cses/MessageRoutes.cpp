#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > edges;
int INF = 1e8 + 5;
int mx = 2e5 + 7;
vector<int> dist(mx, INF);
vector<bool> visited(mx);


int main() {
	int n, m; cin >> n >> m;
	vector<vector<int> > graph(mx, vector<int>());
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dist[1] = 0;

	queue<pair<int, int> > q;
	q.push(make_pair(1, 0));
	visited[1] = true;
	stack<int> res;
	bool found = false;


	while (!q.empty()) {
		pair<int, int> tp = q.front(); q.pop();
		if (tp.first == n) {
			int curr = n;
			int len = dist[curr];
			res.push(n);
			found = true;
			while (curr != 1) {
				for (int kid : graph[curr]) {
					if (dist[kid] == len - 1) {
						curr = kid;
						res.push(kid);
						len--;
						break;
					}
				}
			}

		} else {
			for (auto child : graph[tp.first]) {
				if (visited[child]) continue;
				visited[child] = true;
				q.push(make_pair(child, tp.second + 1));
				dist[child] = tp.second + 1;
			}
		}

	}

	if (found) {
		cout << res.size() << endl;
		while (!res.empty()) {
			int tp = res.top(); res.pop();
			cout << tp << " ";
		}
	} else {
		cout << "IMPOSSIBLE\n";
	}
	return 0;
}