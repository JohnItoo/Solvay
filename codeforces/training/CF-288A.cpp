#include <bits/stdc++.h>
using namespace std;

char intochar(int a) {
	return a + 'a';
}

int main() {
	int n, k; cin >> n >> k;
	if (k > n || (n > 1 && k == 1)) {
		cout << -1 ;
		return 0;
	}

	int abs = n - k + 2;
	string res = "";
	for (int i = 0; i < abs; i++) {
		if (i % 2 == 0) res.push_back('a');
		else res.push_back('b');
	}
	if (res.length() > n) {
		string ans = res.substr(0, n);
		cout << ans << "\n";
		return 0;
	}


	int last = 2;
	char next = res.length() == 0 ? 'a' : intochar(last);
	int left = n - abs;

	while (left && last <= 25) {
		res.push_back(intochar(last));
		last++;
		left--;
	}
	if(left) {
		cout << - 1 << "\n";
		return 0;
	}
	cout << res << "\n";


	return 0;
}