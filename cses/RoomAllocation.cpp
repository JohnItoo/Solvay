#include <bits/stdc++.h>
using namespace std;


int main() {
	int n; cin >> n;
	set<pair<pair<int, int>, int> > times;

	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		times.insert(make_pair(make_pair(x, y), i));
	}


	vector<int> res(n, -1);

	int room = 0;
	int i = 0;


	while (times.size() != 0) {
		auto it = times.begin();
		room++;

		while (it != times.end()) {
			pair<pair<int, int> , int> last = *it;

			times.erase(it);

			int idx = last.second;
			int beg = last.first.first;
			int end = last.first.second;


			res[idx] = room;

			pair<pair<int, int> , int> f = make_pair(make_pair(end + 1, end + 1), 0);
			it = times.upper_bound(f);

		}
	}

	cout << room << "\n";
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	cout << "\n";


}