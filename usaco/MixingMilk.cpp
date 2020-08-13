#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);
	int am, a, bm, b, cm, c = 0;
	cin >> am >> a >> bm >> b >> cm >> c;

	int prs = 0;


	while (prs < 100) {

		int mn = min(a, bm - b);
		a -= mn;
		b += mn;
		prs++;



		if (prs < 100) {
			int mn = min(cm - c, b);
			b -= mn;
			c += mn;
			prs++;
		}


		if (prs < 100) {
			int mn = min(am - a, c);
			c -= mn;
			a += mn;
			prs++;
		}

	}

	cout << a << "\n" << b << "\n" << c << "\n";

	return 0;
}