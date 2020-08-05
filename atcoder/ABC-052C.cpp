#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;

int main() {
	int n; cin >> n;

	long long fact = 1;
	long  long ans = 0;
	map<long long, int> fq;
	for (int i = 1; i <= n; i++) {
		fact *= i;
		fact %= mod;

		for (int j = 1 ; j <= fact; j++) {
			if (fact % j == 0 && fq.find(j) == fq.end()) {
				ans++;
				fq[j] = 1;
			}
		}
	}



	cout << ans << "\n";

}