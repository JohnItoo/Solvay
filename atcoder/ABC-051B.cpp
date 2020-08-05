#include <bits/stdc++.h>
using namespace std;

int main() {
	int s, k; cin >> k >> s;
	if(s == 0 || k * 3 == s) {
		cout << 1 << "\n";
	} else {
		int ans = 0;
		for(int i = k; i > 0; i--) {
			int j = (s - i + 1) / 2;
			if(j > k) break;
			else {
				ans += 1;
			}
		}
		cout << ans * 3 << "\n";
	}
}