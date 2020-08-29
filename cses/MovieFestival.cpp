#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;

	return a.second < b.second;
}



int main() {
	int n;
	cin >> n;
	vector<pair<int, int> > movies;
	vector<bool> done(n, false);
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		movies.push_back(make_pair(x, y));
	}
	sort(movies.begin(), movies.end(), comp);

	int curr = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (done[i]) continue;
		pair<int, int> currMovie = movies[i];
		curr = 1;
		done[i] = true;
		for (int j = 0; j < n; j++) {
			if (done[j]) continue;
			pair<int, int> can = movies[j];

			if (can.first >= currMovie.second) {
				curr++;
				done[j] = true;

			}
		}
		ans = max(ans, curr);
	}
	cout << ans << "\n";
}