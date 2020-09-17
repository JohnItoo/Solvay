#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool cmp (pair<ll, ll> a, pair<ll, ll>b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

int main() {
	int n; cin >> n;
	vector<pair<ll, ll> > pairs;

	for (int i = 0 ; i < n; i++) {
		int x, y; cin >> x >> y;
		pairs.push_back(make_pair(x, y));
	}
	sort(pairs.begin(), pairs.end(), cmp);


	long long start = 0;
	long long ans = 0;
	int i = 0;
	while (i < pairs.size()) {
		pair<ll, ll> curr = pairs[i];
		long long finish =  start + curr.first;
		ans += curr.second - finish;
		start = finish;
		i++;
	}
	cout << ans << "\n";

}