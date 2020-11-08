#include <bits/stdc++.h>
using namespace std;

int main() {
	int g; cin >> g;

	for (int n = 1; n <= g; n++) {
		long long totalPairs = (n * n) * ((n * n) - 1);
		long long totalWaysToPlaceTwo = totalPairs / 2;

		long long waysToPlaceNoAttack = 4 * ( (n - 1) * (n - 2));
		long long ans = totalWaysToPlaceTwo - waysToPlaceNoAttack;
		cout << ans << "\n";
	}


	return 0;
}