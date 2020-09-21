#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n = 1;
	for (int i = 0; i < 10; i++) {
		long long x; cin >> x;
		n *= x;
	}
	vector<int> sv(10005, -1);
	for (int i = 2; i <= 10000; i++) {
		if (sv[i] != -1) continue;

		for (int j = i; j <= 10000; j += i) {

			sv[j] = i;
		}
	}
	vector<int> primes;
	for (int i = 2; i <= n;  i++) {
		if (sv[i] == i) primes.push_back(i);
	}


	vector<int> times;
	for ( int i = 0; i < primes.size(); i++) {
		int prime = primes[i];
		int ct = 0;

		while (n > 0 && n % prime == 0) {
			n /= prime;
			ct++;
		}
		if (ct > 0) times.push_back(ct + 1);
		if (n == 0) break;
	}
	long long ans = 1;

	for (int time : times) {
		ans *= (long long) time;
	}


	cout << ans % 10 << endl;


	return 0;
}