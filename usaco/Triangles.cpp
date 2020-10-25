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

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (i == k || i == j || k == j) continue;
				vector<pair<int, int> > triangle;
				triangle.push_back(vertices[i]);
				triangle.push_back(vertices[j]);
				triangle.push_back(vertices[k]);

				sort(triangle.begin(), triangle.end());
				int b = 0;
				int h = 0;
				if (triangle[0].second == triangle[1].second && triangle[1].first == triangle[2].first) {
					b = triangle[1].first - triangle[0].first;
					h = triangle[2].second - triangle[1].second;
				} else if (triangle[0].first == triangle[1].first && triangle[0].second == triangle[2].second) {
					b = triangle[2].first - triangle[0].first;
					h = triangle[1].second - triangle[0].second;
				} else if (triangle[0].first == triangle[1].first && triangle[1].second == triangle[2].second) {
					b = triangle[2].first - triangle[1].first;
					h = triangle[1].second - triangle[0].second;
				} else if (triangle[0].second == triangle[2].second && triangle[2].first == triangle[1].first) {
					b = triangle[2].first  - triangle[0].first;
					h = triangle[2].second - triangle[1].second;
				}

				int curr = (b * h);
				ans = max(ans, curr);
			}
		}
	}
	cout << ans << "\n";

	return 0;
}