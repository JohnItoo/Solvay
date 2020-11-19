#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main() {
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ans  = 0;
	if(b < c || d < a) {
		ans = (b-a) + (d-c);
	}  else {
		int mn = min(min(a,b), min(c,d));
		int mx = max(max(a,b), max(c,d));
		ans = mx - mn;
	}

	cout << ans << endl;


	return 0;
}