#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll x, y, a, b;
	cin >> x >> y >> a >> b;

	ll res = 0;

	while (x < y / a && x * a <= x + b) {
		res++;
		x *= a;
	}
	ll ans = (y - x - 1) / b;
	cout << ans + res << '\n';
	return 0;
}