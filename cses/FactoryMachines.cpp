#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll n, t; cin >> n >> t;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	vector<ll> nw(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		nw[i] = nw[i - 1] + a[i-1];
		cout << nw[i] << " ";
	}
	cout << "\n";

	ll cycles = t / nw[n]; // time = a[n-1] * cycles;

	t -= cycles * nw[n];
	cout << cycles << " this is t \n";

	int j = 0;
	for (int i = 1; i <= n; i++) {
		t -= nw[i];
		j = i;
		if (t <=  0) break;
	}


	ll ans  = (a[n - 1] * cycles) + a[j - 1];
	cout << ans << "\n";





}