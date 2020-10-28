#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);
	int ans = 0;

	int n; cin >> n; 
	vector<pair<int,int > > a(n);
	for(int i = 0; i < n; i++) {
		int x,y; cin >> x >> y;
		a[i] = make_pair(x-y, x+y); 
	}
	sort(a.begin(), a.end());

	pair<int, int> last = make_pair(0, 0);
	int sz = n;

	for(int i = 0; i < n; i++) {
		if(a[i].second <= last.second && a[i].first >= last.first ) {
			sz--;

		}
		int l = min(a[i].first, last.first);
		int r = max(a[i].second, last.second);
		last = make_pair(l, r);
	}
	

	cout << sz << "\n";

	return 0;
}