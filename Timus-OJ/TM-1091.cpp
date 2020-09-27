#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> fact(52, 0);

void factorial() {
	fact[0] = 1;
	fact[1] = 1;

	for (ll i = 2; i <= 50; i++) {
		fact[i] = i * fact[i - 1];
		cout << fact[i] << "\n";
	}
}

int main() {

	factorial();
	int k, s;
	cin >> k >> s;
	ll res = 0;
	for (int i = 2; i * k <=  s; i++) {
		int N = 0;
		for (int j = 1; i * j <= s; j++) {
			N++;
		}
		cout << i << " " << N << "\n";
		if (N >= k) {
			ll ans  = 0;
			if ((fact[k] * (fact[N - k])) != 0) {
				cout << fact[N] << " facrt N\n";
				ans = (fact[N]) / (fact[k] * (fact[N - k]));
			}
			res += ans;
		}
	}


	cout << res << "\n";

	return 0;
}