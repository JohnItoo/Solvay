#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int n = s.length();
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	int i = n - 1;
	int ct = 0;
	while (i >= 0) {
		ct++;
		i -= 2;
	}

	bool allzs = true;
	for (int i = 1; i < n; i++) {
		if (s[i] == '1') allzs = false;
	}
	if (allzs && (n & 1)) ct--;
	cout << ct << endl;
	return 0;
}