#include <bits/stdc++.h>
using namespace std;

vector<string> house(1000);
vector<vector<bool> > visited(1000, vector<bool>(1000, false));

void walk(int i, int j, int n, int m) {
	if (i < 0 || i >= n || j < 0 || j >= m) return;
	if (house[i][j] == '#' || visited[i][j]) return;
	visited[i][j] = true;
	walk(i + 1, j, n, m);
	walk(i - 1, j, n, m);
	walk(i, j + 1, n, m);
	walk(i, j - 1, n, m);
}

int main() {
	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> house[i];
	}
	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (house[i][j] == '#') continue;
			if (visited[i][j]) continue;
			walk(i, j, n , m);
			ans++;
		}
	}
	cout << ans << "\n";

	return 0;
}