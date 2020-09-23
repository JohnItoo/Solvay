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

			int dx = a.first - b.first; //x,y
			int dy = a.second - b.second;// a,b

			h = dy == 0;
			v = dx == 0;

			int m = 0;
			int c = 0;


			if (!h && !v) {
				m =  dy / dx;
				c =  b.second - (m * b.first);
			}



			int count = 0;
			ii last = b;
			for (int k = 0; k < n; k++) {
				if (k == i || k == j) continue;
				ii curr = rh[k];

				if (h) {
					if (curr.second == last.second) {
						count++;
					}
				} else if (v) {
					if (curr.first == last.first) {
						count++;
					}
				} else {
					if (curr.first == last.first) continue;
					int currm = (curr.second - last.second) / (curr.first - last.first);
					int lef = (b.second - a.second) * (curr.first - a.first);
					int rt = (b.first - a.first) * (curr.second - a.second);



					if (lef == rt) {
						count++;
					}
				}
			}
			best = max(best, count + 2);

		}
	}
	cout << best << endl;
	return 0;
}