#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; double r;
	cin >> n >> r;
	vector<pair<double, double> > nails;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		pair<double, double> nail = make_pair(x, y);
		nails.push_back(nail);

	}

	return 0;
}