#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long sum = (n * (n + 1)) / 2;
	if ((sum & 1) ) {
		cout << "NO\n";
	} else {
		vector<int> a;
		vector<int> b;
		bool who = true;
		int curr = 1;
		while (curr <= n) {
			if (who) {
				a.push_back(curr);
				curr += 1;
				if (curr <= n) {
					a.push_back(curr);
					curr += 1;
				}
				if (curr  <= n) {
					b.push_back(curr);
					curr += 1;
				}
				who = false;
			} else {
				a.push_back(curr);
				curr += 1;
				if (curr  <= n) {
					b.push_back(curr);
					curr += 1;
				}
				if (curr <= n) {
					b.push_back(curr);
					curr += 1;

				}
				who = true;
			}
		}
		cout << "YES\n"; f
		cout << a.size() << "\n";
		for (int i = 0; i < a.size(); i++) {
			cout << a[i] << " ";
		}
		cout << "\n";

		cout << b.size() << "\n";
		for (int i = 0; i < b.size(); i++) {
			cout << b[i] << " ";
		}
		cout << "\n";

	}
}
