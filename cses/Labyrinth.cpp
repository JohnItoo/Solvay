#include <bits/stdc++.h>
using namespace std;
vector<string> room(1500);
vector<vector<bool > > visited(1500, vector<bool>(1500, false));
vector<vector<int> > dist(1500, vector<int>(1500, -1));
int n = 0 , m = 0;

string ans = "";
map<char, pair<int, int> > mv;


void walk(int row, int col) {


	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(row, col), 0));
	visited[row][col] = true;
	dist[row][col] = 0;

	while (!q.empty()) {
		pair<pair<int, int>, int> tp = q.front(); q.pop();
		int row = tp.first.first;
		int col = tp.first.second;
		int d = tp.second;
		dist[row][col] = d;


		if (room[row][col] == 'B') {
			string res;
			//backtrack and build

			while (room[row][col] != 'A') {
				if (row > 0 && dist[row - 1][col] == d - 1) {
					res.push_back('D');
					row--;
				} else if (row < n - 1 && dist[row + 1][col] == d - 1) {
					res.push_back('U');
					row++;
				} else if (col > 0 && dist[row][col - 1] == d - 1) {
					res.push_back('R');
					col--;
				} else  {
					res.push_back('L');
					col++;
				}
				d--;
			}
			reverse(res.begin(), res.end());
			ans = res;
			break;
		} else {
			for (auto ii : mv) {

				int nr = mv[ii.first].first + row;
				int nc = mv[ii.first].second + col;
				if (nr < 0 || nr >= n || nc < 0 || nc >= m || room[nr][nc] == '#') continue;
				if (visited[nr][nc]) continue;

				visited[nr][nc] = true;
				pair<pair<int, int>, int > np = make_pair(make_pair(nr, nc), d + 1);
				q.push(np);
			}
		}

	}


}

int main() {
	cin >> n >> m;
	int r = -1, c = -1;
	mv['U'] = make_pair(-1, 0);
	mv['D'] = make_pair(1, 0);
	mv['L'] = make_pair(0, -1);
	mv['R'] = make_pair(0, 1);
	for (int i = 0; i < n; i++) {
		cin >> room[i];
		for (int j = 0; j < m; j++) {
			if (room[i][j] == 'A') {
				r = i;
				c = j;
			}

		}
	}
	walk(r, c);
	if (ans == "") {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		cout << ans.length() << "\n";
		cout << ans << "\n";
	}

	return 0;
}