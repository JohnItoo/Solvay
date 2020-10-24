#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("lostcow.in", "r", stdin);
	// freopen("lostcow.out", "w", stdout);
	int ans = 0;

	int i = 1;
	int x, y; cin >> x >> y;
	int curx = x;
	bool plus = true;
	// while ((y < currx && y < currx + i) || (y > currx && y > currx + i) ) {
	// 	currx += i;
	// 	ans += abs(i);

	// 	i *= -2;
	// 	cout << x << "\n";
	// }
	// cout << ans + abs(currx - y)<< "\n";
	while(true) {
		// Go to the new x.
		   cout << curx << " " << i << " curx \n";
			int newx = x + i;
			int mn = min(curx,newx);
			int mx = max(curx,newx);
			int travel = abs(curx-newx);

			// We made it, get out.
			if (mn <= y &&  y <= mx) {
				ans += abs(y-curx);
				break;
			}

			// Go to next iteration.
		     i *= (-2);
			ans += travel;
			curx = newx;
	}
	cout << ans << "\n";


	return 0;
}