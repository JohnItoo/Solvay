#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	string s; cin >> s;

	int count = 0;
	char last = '.';
	int lastdx = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '.' && last != 'R') count++;

		if (s[i] == 'L') {
			if (last == 'R') {
				int diff = i - lastdx;
				if (diff % 2 == 0) {
					count += 1;
				}
				last = '.';
			} else {
				count = 0;
			}
		}

		if (s[i] == 'R')  {
			last = 'R';
			lastdx = i;

		}
	}
	cout << count << "\n";

	return 0;
}