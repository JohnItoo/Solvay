#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

// This solution uses Modulo Exponentiation.
long long modPow(int x, long long n) {
	if (n == 0) return 1 % mod;
	long long u = modPow(x, n / 2);
	u = (u * u) % mod;
	if (n & 1) {
		u = (u * x) % mod;
	}
	return u;
}

int main() {
	long long n;
	cin >> n;
	cout <<  modPow(2, n) << "\n";

}