#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long p[n];
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	sort(p , p + n);

	int trail = n - 1;
	int front = 0;

	long long sumA = 0;
	long long sumB = 0;
   
	while (trail >= front) {
		if (sumA < sumB) {
			sumA += p[front++];
		} else {
			sumB += p[trail--];
		}
	}
	cout << sumB << "\n";
	cout << abs(sumA - sumB) << "\n";

}