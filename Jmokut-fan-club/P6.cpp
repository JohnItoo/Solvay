#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int main() {

	int n; cin >> n;
	vector<pair<int, int> > rh;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		rh.push_back(make_pair(x, y));
	}

	int best = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			bool h = false;
			bool v = false;

			ii a = rh[i];
			ii b = rh[j];

			int dx = a.first - b.first;
			int dy = a.second - b.second;

			h = dy == 0;
			v = dx == 0;

			int m = 0;
			int c = 0;


			if (!h && !v) {
				m = dy / dx;
				c = b.second - (m * b.first);
			}

			cout << c << " This is intercept \n";

			int count = 2;
			ii last = b;
			for (int k = 0; k < n; k++) {
				if (k == i || k == j) continue;
				ii curr = rh[k];

				if (h) {
					if (curr.second == last.second) {
						// last = curr;
						count++;
					}
				} else if (v) {
					if (curr.first == last.first) {
						// last = curr;
						count++;
					}
				} else {
					if (curr.first == last.first) continue;
					int currm = (curr.second - last.second) / (curr.first - last.first);

					if (curr.second - (currm *  curr.first) == c) {
						// last = curr;
						count++;
					}
				}
			}
			best = max(best, count);

		}
	}
	cout << best << endl;
	return 0;
}