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
			for (int k = 0; k < n; k++) {
				if (i == k || i == j || k == j) continue;

			}
		}
	}







	return 0;
}