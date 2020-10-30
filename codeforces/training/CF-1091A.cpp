#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c; cin >> a >> b >> c;
	int y = min(a, min(c - 2, b - 1));
	cout << 3 * y + 3 << "\n";
	return 0;
}