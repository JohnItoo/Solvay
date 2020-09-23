#include <bits/stdc++.h>
using namespace std;
#define pdd pair<double, double>
# define EM_PI 3.14159265358979323846


int main() {
	int n; double r;
	cin >> n >> r;
	vector<pdd > nails;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		pdd nail = make_pair(x, y);
		nails.push_back(nail);
	}

	double per = 0.0;
	pdd prev = make_pair(-900, 900);
	bool first = true;

	while (nails.size() >= 1) {
		if (first) {
			first = false;
			prev = *nails.begin();
			nails.erase(nails.begin());
			continue;
		}
		pdd curr = *nails.begin();
		double diff = abs(prev.first - curr.first) + abs(prev.second - curr.second);
		per += diff;
		prev = curr;
		nails.erase(nails.begin());
	}

	per += (2 * EM_PI * r);
	printf("%.2f\n", per);

	return 0;
}