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
		for (int j = i + 1; j < n; j++) {
			bool holds = true;
			for (int row = 1; row < k; row++) {
				for (int q = 0; q < n; q++) {
					if (cows[row][q] == cows[0][i]) {
						break;
					} else if (cows[row][q] == cows[0][j]) {
						holds = false;
						break;
					}
				}
				if (holds) continue;
				else break;
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