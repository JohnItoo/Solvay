#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> a[26];
	string s;
	cin >> s;
	int n = s.length();
	int l = -1, r = -1;
	for (int i = 0; i < n ; i++) {
		int val = s[i] - 'a';
		a[val].push_back(i + 1);
	}
	for (int i = 0; i < 26; i++) {
		if (a[i].size() < 2) continue;
		bool found = false;
		for (int j = 0; j < a[i].size() - 1; j++) {
			if (a[i][j + 1] - a[i][j] <= 2) {
				l = a[i][j];
				r = a[i][j + 1];
				found = true;
				break;
			}

		}
		if (found) break;
	}
	cout << l << " " << r << "\n";

	return 0;
}