#include <bits/stdc++.h>
using namespace std;
int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		long long a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		if(a == 0) {
          if(b == 0) cout << "YES\n";
          else cout << "NO\n";
		} else {
		long long ans = (2 * a) - b;
		if (ans % 3 == 0 && (ans / 3) > 0) cout << "YES\n";
		else cout << "NO\n";
		}
		
	}
}