#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; cin >> tc;
	while (tc--) {
		string s; cin >> s;
		int lef = 0;
		while (lef < s.length() && s[lef] == 'B') lef++;

		int rig = s.length() - 1;
		while (rig >= 0 && s[rig] == 'A') rig--;

		int st = (rig - lef ) + 1;
		int rem = st & 1;
		cout << rem + (s.length() - 1 - rig) + lef << "\n";
	}

	return 0;
}