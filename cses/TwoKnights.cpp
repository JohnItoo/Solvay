#include <bits/stdc++.h>
using namespace std;

int main() {
	int g; cin >> g;

	//Total Number of ways to place 2 things on n*n cells is  = n^2(n^2 + 1) / 2;
	//A knight will attack in a 2*3 or 3*2 square.  Number of 2*3 squares + number of 3* 2 squares ==
	// (n-2)(n-1) + (n-1)(n-2) = 2(n-1)(n-2)
	// but each of these above ways has 2 ways of placing 2 knights = 4(n-1)(n-2)

	// answer is n^2(n^2 + 1) / 2 - 4(n-1)(n-2)
	for (int n = 1; n <= g; n++) {
		long long sq = (n * n);
		long long totalPairs = sq * (sq - 1);
		long long totalWaysToPlaceTwo = totalPairs / 2;

		long long waysToPlaceAttacks = 4 * ( (n - 1) * (n - 2));
		long long ans = totalWaysToPlaceTwo - waysToPlaceAttacks;
		cout <<  ans << "\n";
	}

	return 0;
}