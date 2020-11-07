#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; cin >> tc;
	while (tc--) {
		int a , b; cin >> a >> b;
		string s; cin >> s;
		int n = s.length();
		int i = 0;
		int j = n - 1;

		while (i < n && s[i] == '0') i++;

		while (j >= 0 && s[j] == '0') j--;

		int tz = 0;
		int c1 = 0;
		for (int q = i; q <= j; q++) {
			if (s[q] == '0') {
				tz++;
			} else {
				if ((q == i) || (q - 1 >= 0  && s[q - 1] == '0')) c1++;
			}

		}
		int ans = min(c1 * a, (tz * b) + a);
		cout << ans << "\n";

	}
	return 0;
}