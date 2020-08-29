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
	while (!movies.empty()) {
		auto it = movies.begin();
		pair<int, int> currMovie = *it;
		curr = 1;
		// done[i] = true;
		// vector<int> rem;
		// rem.push_back(0);
		// int j = 1;
		movies.erase(it);
		pair<int, int> findMovie = make_pair(currMovie.second, currMovie.second + 1);
		it = lower_bound(movies.begin(), movies.end(), findMovie, comp);

		// movies.erase(movies.begin());
		while (it != movies.end()) {
			pair<int, int> can = *it;
			// cout << can.first << " " << can.second << "\n";

			if (can.first >= currMovie.second) {
				curr++;
				movies.erase(it);
				currMovie = can;
				findMovie = make_pair(currMovie.second, currMovie.second + 1);
				it = lower_bound(movies.begin(), movies.end(), findMovie, comp);

			} else {
				++it;
			}
		}


		ans = max(ans, curr);
	}
	cout << ans << "\n";
}