#include <bits/stdc++.h>
using namespace std;

int main() {
	long long x;
	cin >> x;
	long long sum = 0;
	long long i = 1;
	while(sum < x) {
       sum += i;
       i++;
	}
	cout << i-1 << "\n";
}