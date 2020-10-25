#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);
	int k, n; cin >> k >> n;
	vector <vector<int> > cows(k, vector<int>(n));

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cows[i][j];
		}
	}

	int ans = 0;
	set<pair<int, int> > prs;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (cows[0][i] <= cows[0][j]) continue;
			bool holds = true;
			for (int row = 1; row < k; row++) {
				if (cows[row][i] <= cows[row][j]) {
					holds = false;
					break;
				}
			}
			vector<int> dz;
			if (holds) {
				dz.push_back(i);
				dz.push_back(j);
				sort(dz.begin(), dz.end());
				prs.insert(make_pair(dz[0], dz[1]));
			}


		}
	}
	cout << prs.size() << "\n";


	return 0;
}