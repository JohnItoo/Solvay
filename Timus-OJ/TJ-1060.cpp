#include <bits/stdc++.h>
using namespace std;

map<string, int> visited;
map<string, int> level;
int mx = 1e9 + 5;
int best = mx;
int dir[4][2] = { { 1, 0}, {0, 1}, { -1, 0}, {0, -1} };

bool isResult(string s) {
	char c = s[0];
	for (int i = 1; i < 16; i++) {
		if (s[i] != c) {
			return false;
		}
	}
	return true;
}

string flip(string state, int i) {
	int row = (i / 4);
	int col = i - (4 * row);
	state[i] = (state[i] == 'w') ? 'b' : 'w';

	for (int g = 0; g < 4; g++) {
		int nr = row + dir[g][0];
		int nc = col + dir[g][1];
		int calc = nc + (nr * 4);
		if (calc < 0 || calc > 15) continue;
		state[calc] = (state[calc] == 'w') ? 'b' : 'w';
	}
	return state;
}

void bfs(string board) {

	queue<string> q;
	q.push(board);
	string prev = "";
	level[board] = 0;

	while (!q.empty()) {
		string state = q.front(); q.pop();
		if (visited.find(state) != visited.end()) continue;
		visited[state] = 1;
		auto it = (level.find(state));
		if (isResult(state)) {
			if (it != level.end() && it->second < best) {
				best = it->second;
			}
		}


		for (int i = 0; i < 16; i++) {

			string newstate = flip(state, i);

			level[newstate] = it->second + 1;

			q.push(newstate);
		}


	}
}

int main() {
	string board = "";

	for (int i = 0; i < 4; i++) {
		string s; getline(cin, s);
		board += s;
	}

	bfs(board);
	if (best == mx) {
		cout << -1 << "\n";
	} else {
		cout << best << "\n";
	}

	return 0;
}