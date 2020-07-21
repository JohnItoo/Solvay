#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	long long x[n];
	for(long long &i : x) {
		cin >> i;
	}
	long long needs = 0;
	for(int i = 1; i < n; i++) {
		if (x[i-1] > x[i]) {
			needs += x[i-1] - x[i];
			x[i] = x[i-1];
		}
	}
	cout << needs <<"\n";
}