#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> a[26];
	string s;
	cin >> s;
	int n = s.length();
	int l = -1, r = -1;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) {
			l = i;
			r = i + 1;
			break;
		}
	}
	cout << l << " " << r << "\n";

	return 0;
}