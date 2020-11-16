#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	long long ans = 0;
	int curr = 1;
	int power = 1;
	cin >> n;
	curr = n;

	while (curr >= 5) {
		int dz = curr/5;
		curr = dz;
		ans += (long long) curr;
	}

	cout << ans << endl;

}