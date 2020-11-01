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
		int stub = rem + (s.length() - 1 - rig) + lef;
		if ((lef + rem) % 2 == 0) stub -= lef + rem;
		else {
			int df = lef / 2;

			stub -= (df * 2);
		}
		cout << stub << "\n";
	}

	return 0;
}