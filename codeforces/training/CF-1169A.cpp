#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a , x , b , y; cin >> n >> a >> x >> b  >> y;

	while(a != x && b != y && a != b) {
		if(a == n) {
			a = 1;
		} else {
			a++;
		}

		if(y == 1) {
			y = n;
		} else {
			y--;
		}
	}
	if(a == b) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	return 0;
}