#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a , x , b , y; cin >> n >> a >> x >> b  >> y;

	int time = abs(a - b);
	if (time % 2 == 0) {
		int lef = x < a ? (n - x ) + (x - a) : x - a;
		int right = y > b ? (b - 1) + (n - y) : n - y;
		if (lef >= time && right >= time) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}

	} else {
		cout << "NO\n";
	}

	return 0;
}