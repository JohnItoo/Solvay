#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long inter = n/5;
	long long ans = (inter/4) - 1;
	cout << inter + ans  << "\n";
}