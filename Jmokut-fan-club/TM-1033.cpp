#include <bits/stdc++.h>

using namespace std;

vector<vector<bool > > visited(40, vector<bool> (40, false));
vector<vector<char > > grid(40, vector<char>(40));

int dir[4][2] = { { -1, 0}, {1, 0}, {0, -1}, {0, 1} };
int ans = 0;
int n = 0;


void bfs(int x, int y) {

	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	visited[x][y] = true;

	while (!q.empty()) {
		pair<int, int > curr = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = curr.first + dir[i][0];
			int ny = curr.second + dir[i][1];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) ans++;
			else if (grid[nx][ny] == '#') ans++;
			else if (!visited[nx][ny]) {
				pair<int, int> ii = make_pair(nx, ny);
				q.push(ii);
				visited[nx][ny] = true;
			}
		}
	}
}



int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		for (int j = 0; j < n; j++) {
			grid[i][j] = x[j];
		}
	}

	bfs(0, 0);
	if (!visited[n - 1][n - 1]) {
		bfs(n - 1, n - 1);
	}

	cout << (ans - 4) * 9 << "\n";


	return 0;
}