#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, b, c; cin >> a >> b >> c;
	long long ans = (2 * b) + ((2 * c) - 2);
	ans += (b - 1) * (c - 1);
	cout << ans << "\n";
}