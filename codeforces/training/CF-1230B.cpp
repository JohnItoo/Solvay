#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	string s;
	cin >> s;
	if (s.length() >= 2) {
		if (s[0] != '1' && k > 0) {
			s[0] = '1';
			k--;
		}
		for (int i = 1; i < s.length() && k > 0; i++) {
			if (s[i] != '0') {
				s[i] = '0'; k--;
			}
		}
	} else {
		if(k > 0) s = "0";
	}
	cout << s << "\n";
	return 0;
}
