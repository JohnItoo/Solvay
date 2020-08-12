#include <bits/stdc++.h>
#include <tuple>
using namespace std;

int main() {
	int n; cin >> n;
	set<tuple<int, int, int>>vp;
	vector<tuple<int, int, int>> tuples(n);
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		tuples[i] = make_tuple(x, y, i);
	}
	sort(tuples.begin(), tuples.end());

	for(int i = 0; i < n; i++) {
		vp.insert(tuples[i]);
	}
	vector<int> result(n);
	int arriv = 0; int dep = 0;
	int room = 1;

	while (vp.size() > 0) {
		auto it = vp.upper_bound(make_tuple(0, 0, 0));
		tuple<int, int, int> pr = *it;
		int come, leave , index;
		tie(come, leave, index) = pr;

		// cout << index << " index \n";
		result[index] = room;
		vp.erase(it);
		auto jt = vp.upper_bound(make_tuple(leave, 0, 0));
		if (jt != vp.end()) ++jt;


		while (jt != vp.end()) {
			int c, l, i = 0;

			tie(c, l, i) = *jt;
			result[i] = room;
			// cout << i << "index \n";
			vp.erase(jt);
			leave =  l;
			jt = vp.upper_bound(make_tuple(leave, 0, 0));
		}
		room++;
	}
	cout << *max_element(result.begin(), result.end()) << "\n";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

}