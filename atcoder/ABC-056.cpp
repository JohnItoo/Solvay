#include <bits/stdc++.h>
using namespace std;

int main() {
	long long x;
	cin >> x;
	long long c = x * 2;
	// cout << c << "\n";
	long long div = 1 + (4 *c);
	// cout << div << "\n";
	long long root = pow(div, 0.5);
	// cout << root << "\n";
	if(root * root == div) {
		long long ans = (root - 1) / 2;
		cout << ans << "\n";
	} else {
		cout << x << "\n";
	}
}