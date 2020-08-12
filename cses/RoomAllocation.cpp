#include <bits/stdc++.h>
#include <tuple>
using namespace std;

bool comp(pair<int, int> a , pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}
int main() {
	int n; cin >> n;
	set<tuple<int, int, int> >vp;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		vp.insert(make_tuple(x, y, i));
	}
	vector<int> result(n);
	int arriv = 0; int dep = 0;
	int room = 1;

	while (vp.size() > 0) {
		auto it = vp.lower_bound(make_tuple(0, 0, 0));
		tuple<int, int, int> pr = *it;
		int come, leave , index;
		tie(come, leave, index) = pr;
		auto jt = vp.upper_bound(make_tuple(leave, 0, 0));


		while (jt != vp.end()) {
			int c, l, i = 0;
			tie(c, l, i) = *jt;
			result[i] = room;
			vp.erase(jt);
			leave =  l
			         jt = vp.upper_bound(make_tuple(leave, 0, 0));
		}
		room++;
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}

}