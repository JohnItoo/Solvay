#include <bits/stdc++.h>
using namespace std;
int main() {
	long long a, b, c, d ; cin >> a >> b >> c >> d;
	long long x = ((c - a) + (b + d - 1)) / (b + d);
	cout << a + (b * x) << endl;


	return 0;
}