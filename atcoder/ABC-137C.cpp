#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	vector<string> strings(n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		sort(s.begin(), s.end());
		strings[i] = s;
	}
	sort(strings.begin(), strings.end());
	long long ans = 0;
	long long curr = 0;
	for (int i = 1; i < n; i++) {
		if (strings[i] == strings[i - 1]) {
			curr++;
		} else {

			long long dict = (curr * (curr + 1)) / 2;
			ans += dict;
			curr = 0;

		}
	}
	long long dic = (curr * (curr + 1)) / 2;
	if (dic >= 0) ans += dic;

	cout << ans << "\n";
}