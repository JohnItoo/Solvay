#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	long long ans = 0;
	int curr = 1;
	int power = 1;
	cin >> n;

	while ((1 << power) <= n ) {
		int curr = (1 << power) / 5;
		ans = (long long) (ans +  curr);
		power++;
	}

	cout << ans << endl;

}