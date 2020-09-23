#include <bits/stdc++.h>
using namespace std;
#define pdd pair<double, double>
# define EM_PI 3.14159265358979323846

double distance(pdd a, pdd b) {
	double xs = pow(a.first - b.first, 2);
	double ys = pow(a.second - b.second, 2);
	return pow(xs + ys, 0.5);
}

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
	pdd prev = nails[0];
	bool first = true;
	int i = 1;


	while (i < n) {

		pdd curr = nails[i];
		double diff = distance(curr, prev);
		per += diff;
		prev = curr;
		i++;
	}

	per += distance(nails[0], nails[n - 1]);

	per += (2 * EM_PI * r);
	printf("%.2f\n", per);

	return 0;
}