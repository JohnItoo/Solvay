#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;

int main() {
	int n; cin >> n;

	long long fact = 1;
	long  long ans = 0;
	long long lstVstd = 1;
	map<long long, int> fq;
	for (int i = 1; i <= n; i++) {
		fact *= i;

		for (int j = lstVstd ; j <= fact; j++) {
			if (fact % j == 0 && fq.find(j) == fq.end()) {
				ans++;
				fq[j] = 1;
			}
		}
		fact %= mod;

	}



	cout << ans << "\n";

}