#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	double ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (double) 1 / a[i];
	}

	printf("%.9f\n",  1 / ans);
}