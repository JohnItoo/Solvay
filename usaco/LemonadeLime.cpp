#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("lemonade.in", "r", stdin);
	freopen("lemonade.out", "w", stdout);
	int ans = 0;

	int n; cin >> n; 
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());

	int i = 0;
	while(i < n && a[i]  >= i)  i++;

	cout << i << "\n";

	return 0;
}