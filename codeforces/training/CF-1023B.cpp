#include <bits/stdc++.h>
using namespace std;

int main() {
		long long n, k;
	cin >> n >> k;
	long long left = k/2;
	long long right =  k - left ;
	if(k % 2 == 0) {
		left -= 1;
		right += 1;
	}
	if(n < left || n < right) {
		cout << 0 << "\n";
	} else {
		long long ans = min(left -1, n - right);
		cout << ans + 1 << "\n";
	}



	return 0;
}