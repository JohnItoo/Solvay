#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	set<pair<long, long> > st;
	for (int i = 0; i < n; i++) {
		long long curr = 0; cin >> curr;
		st.insert(make_pair(curr, i));
	}
	long long ans = 0;
	long long curr = 0;
	int mv = 0;
	while (!st.empty()) {
		auto it = *st.begin();
		int cu = it.first;
		cout << cu << "\n";
		if (curr + cu <= x && mv < 2) {
			curr += cu;
			mv++;
			st.erase(st.begin());


			cout << cu << " ";
		} else {
			curr = 0;
			mv = 0;
			ans++;
			cout << "\n";
		}
	}
	if(curr != 0) ans += 1;
	cout << ans << "\n";
}