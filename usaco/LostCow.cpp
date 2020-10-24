#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("lostcow.in", "r", stdin);
	freopen("lostcow.out", "w", stdout);
	int ans = 0;

	int i = 1;
	int x, y; cin >> x >> y;
	int curx = x;
	bool plus = true;
	while ((y < curx && y < x + i) || (y > curx && y > x + i) ) {

		int mv = x + i;
		ans +=  abs(curx - mv);
		curx = mv;


		i *= -2;
	}
	cout << ans + abs(curx - y) << "\n";


	return 0;
}