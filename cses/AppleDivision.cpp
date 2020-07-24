#include <bits/stdc++.h>
using namespace std;
long long p[20];
int len = 0;
long long sum  = 0;
long long ans = 10e9;
vector<long long> curr;

// We are simply generating all the subsets.

void generate(int i) {
	if (i == len) {
		long long s = 0;
		for (int i = 0; i < curr.size(); i++) {
			s += curr[i];
		}
		long long sub = sum - s;
		ans = min(ans, abs(sub - s));
	} else {
		generate(i + 1);
		curr.push_back(p[i]);
		generate(i + 1);
		curr.pop_back();
	}

}
int main() {
	cin >> len;
	for (int i = 0; i < len; i++) {
		cin >> p[i];
		sum += p[i];
	}

	generate(0);

	cout << ans << "\n";

}