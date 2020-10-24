#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("lostcow.in", "r", stdin);
	// freopen("lostcow.out", "w", stdout);
	int ans = 0;

	int i = 1;
	int x, y; cin >> x >> y;
	bool plus = true;
	while(x  != y) {
      if(plus)  {
      	plus = false;
      	x += i;
      	ans += i;
      } else {
      	plus = true;
      	x -= i;
      	ans += i;
      }
      i *= 2;
      cout << x << "\n";
	}
	cout << ans << "\n";


	return 0;
}