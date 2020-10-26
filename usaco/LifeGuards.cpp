#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {

	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair< int, int> > vii;
	for (int i = 0; i < n; i++) {
		int x , y;
		cin >> x >> y;
		vii.push_back(make_pair(x, y));
	}
	sort(vii.begin(), vii.end(), comp);
	int curr = 0;
	int mx = 0;

	for (int i = 0; i < n; i++) {

		pair<int, int > last;
		curr = 0;
		bool has = false;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (!has) {
				last = vii[j];
				curr = last.second - last.first;
				has = true;
			} else {
				pair<int, int> currP = vii[j];
				if (currP.first <= last.second) {
					int diff = currP.second - (last.second + 1);
					if (diff > 0) curr += diff;
				} else {
					curr += currP.second - currP.first;
				}
				last = currP;
			}
		}
		mx = max(mx, curr);
	}
	cout << mx << "\n";


	return 0;
}