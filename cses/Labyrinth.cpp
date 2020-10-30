#include <bits/stdc++.h>
using namespace std;
vector<string> room(1005);
vector<vector<bool > > visited(1005, vector<bool>(1005, false));
int n = 0 , m = 0;
string ans = "";
map<char, pair<int, int> > mv;


void walk(int row, int col , string path) {
	if (row < 0 || row >= n || col < 0 || col >= m) return;
	if (room[row][col] == '#' || visited[row][col]) return;
	visited[row][col] = true;
	if (room[row][col] == 'B') {
		if (ans == "") {
			ans = path;
		} else {
			if (path.length() < ans.length()) ans = path;
		}

		return;
	}
	for (auto dir : mv) {
		char key = dir.first;
		int nr = mv[key].first + row;
		int nc = mv[key].second + col;
		string npath = path;
		npath.push_back(key);
		walk(nr, nc, npath);
	}
	visited[row][col] = false;
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
	walk(r, c, "");
	if (ans == "") {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		cout << ans.length() << "\n";
		cout << ans << "\n";
	}

	return 0;
}