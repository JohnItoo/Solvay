#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<long long> tickets(n);
	for (int i = 0; i < n; i++) {
		cin >> tickets[i];
	}

	vector<long long> prices(m);


	for (int i = 0; i < m; i++) {
		cin >> prices[i];
	}
	sort(tickets.begin(), tickets.end());

	vector<long long> result(m, -1);

	int i = 0; int j = 0;
	while (i < n && j < m) {
		if (prices[j] < tickets[i]) {
			j++;
		} else {
			if (prices[j] == tickets[i]) {
				result[j] = tickets[i];
				i++; j++;
			} else if (prices[j] > tickets[i]) {
				if (i + 1 >= n  || tickets[i + 1] > prices[j]) {
					result[j] = tickets[i];
					i++; j++;
				} else {
					i++;
				}
			}

		}
	}

	for (int i = 0; i < m; i++) {
		cout << result[i] << "\n";
	}



}