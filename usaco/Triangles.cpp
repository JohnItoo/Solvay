#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);
	int n; cin >> n;
	vector<pair<int, int> > vertices;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		vertices.push_back(make_pair(x, y));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (vertices[i].first == vertices[j].first || vertices[i].second == vertices[j].second) {

				for (int k = 0; k < n; k++) {
					if (k == i || k == j) continue;

					pair<int, int> first = vertices[i];
					pair<int, int> second = vertices[j];
					pair<int, int> third = vertices[k];
					// xequal base

					if (first.first == second.first) {

					}



				}

			}
		}
	}







	return 0;
}