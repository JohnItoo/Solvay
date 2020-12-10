#include <bits/stdc++.h>
using namespace std;
int main() {
	long long a, b, c, d ; cin >> a >> b >> c >> d;
	long long x = ((c - a) + (b + d - 1)) / (b + d);
	x -= 1; 
	cout << max((a + b * x) + b, (c - d*x) -d) << endl;

	return 0;
}