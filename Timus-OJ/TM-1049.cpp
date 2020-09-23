#include <bits/stdc++.h>
using namespace std;

//https://acm.timus.ru/problem.aspx?space=1&num=1049

int main() {
	long long n = 1;

	vector<int> sv(10005, -1);
	for (int i = 2; i <= 10000; i++) {
		if (sv[i] != -1) continue;

		for (int j = i; j <= 10000; j += i) {

			sv[j] = i;
		}
	}
	vector<int> primes;
	for (int i = 2; i <= 10000;  i++) {
		if (sv[i] == i) primes.push_back(i);
	}


	map<int, int> mp;

	for (int i = 0; i < 10; i++) {
		long long x; cin >> x;
		if (x < 2) continue;
		for ( int j = 0; j < primes.size(); j++) {
			int prime = primes[j];

			while (x > 1 && x % prime == 0) {
				x /= prime;
				mp[prime]++;
			}

			if (x <= 1) {
				break;
			}
		}
	}

	long long ans = 1;

	for (auto it : mp) {
		ans *= (it.second + 1);
	}


	cout << ans % 10 << endl;


	return 0;
}