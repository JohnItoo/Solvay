#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	sort(p.begin(), p.end());

	int mdx = n / 2;
	int median  =  p[mdx];

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		ans += abs(median - p[i]);
	}

	cout << ans << "\n";


}