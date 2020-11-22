#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int n; cin >> n;
	vector<ll> a(n);
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a.begin(), a.end());

	int i = 0, j = n-1;
	ll left = a[i];
	ll right = a[j];

	while(i+1 < j) {
		if(left < right) left += a[++i];
		else right += a[--j];
	}

	cout << left << " " << right << endl;


   ll ans = max(left, right) * 2;
   cout << ans << endl;



	return 0;
}