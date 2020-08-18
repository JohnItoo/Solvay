// https://codeforces.com/problemset/problem/804/A

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int i = 1;
	int j = n;
	int visited = n;
	int ans = 0;
	int last = 1;
	while (i < j) {
		ans += (i + j) % (n + 1);
		if (last) {
			i++;
			last = 0;
		} else {
			last = 1;
			j--;
		}
		visited--;
	}
	cout << ans << "\n";


	return 0;
}