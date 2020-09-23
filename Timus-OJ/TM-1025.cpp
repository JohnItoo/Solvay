#include <bits/stdc++.h>
using namespace std;
// https://acm.timus.ru/problem.aspx?space=1&num=1025

int main() {
	int n; cin >> n;
	multiset<int> ms;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		ms.insert(x);
	}
	int it = 0;
	int ans = 0;
	while (it < (n / 2) + 1) {
		it++;
		auto idx = ms.begin();
		int x = *idx;
		ms.erase(idx);
		ans += ((x / 2) + 1);
	}
	cout << ans << "\n";
}