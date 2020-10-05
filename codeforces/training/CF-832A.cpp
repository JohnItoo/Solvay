#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {

	ll a, b; cin >> a >> b;
	ll ans = a/b;

	if(ans & 1) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}