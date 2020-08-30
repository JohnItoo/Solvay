#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n; cin >> n;
	ll global_max = -1e18;
	ll curr_max = -1e18;

	for (int i = 0; i < n; i++) {
		ll curr; cin >> curr;
		curr_max = max(curr, curr_max + curr);
		global_max = max(global_max, curr_max);
		// cout << curr_max << " " << global_max << "\n";
	}

	cout << global_max << "\n";

}