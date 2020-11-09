#include <bits/stdc++.h>
using namespace std;

int recur(int radius, int start,  map<int, int> &mp) {
	int ct = 0;
	for (int i = start; i <= radius + start; i++) {
		if (mp.find(i) != mp.end())ct++;
	}
}

int main() {
	int n; cin >> n;
	vector<int> v(n);
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mp[v[i]]++;
	}
	int ans = 0;

	for (int i = 0; i < n; i++) {
		int curr = 0;
		for (int distance = 0; distance <= n; distance++) {
			for (int j = v[i]; j <= v[i] + distance; )
			}
	}


	return 0;
}