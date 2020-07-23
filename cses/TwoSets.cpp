#include <bits/stdc++.h>
using namespace std;

// GREEDY ; Always pick max till
int main() {
	long long n;
	cin >> n;

	long long sum = (n * (n + 1)) / 2;


	if ((sum % 2 != 0 ) ) {
		cout << "NO\n";
	} else {
		vector<long long> a;
		vector<long long> b;
		map<long long, int> marked;
		long long s = sum / 2;
		long long t = n;
		long long curr = 0;
		long long last = n;
		while (t + curr <= s) {
			a.push_back(t);
			curr += t;
			last = t;
			t--;
		}

		if (s > curr) {
			a.push_back(s - curr);
			marked[s - curr] = 1;
		}

		for (int i = 1; i < last; i++) {
			if (marked.find(i) != marked.end()) continue;
			b.push_back(i);
		}

		cout << "YES\n";
		cout << a.size() << "\n";
		for (int i = 0; i < a.size(); i++) {
			cout << a[i] << " ";
		}
		cout << "\n";

		cout << b.size() << "\n";
		for (int i = 0; i < b.size(); i++) {
			cout << b[i] << " ";
		}
	}
}