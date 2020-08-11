#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	long long x;
	cin >> x;
	int n; cin >> n;
	priority_queue<pair<ll, pair<ll, ll> > > pq;

	vector<long long> ans(n);

	for (int i = 0; i < n; i++) {
		ll pi; cin >> pi;
		pair<ll, pair<ll, ll> > prs;
		pair<ll, pair<ll, ll> > pss;
		if (i == 0) {
			if (x - pi > pi - 1) {
				prs = make_pair(x - pi, make_pair(pi, x));
				// pss = make_pair(pi - 1, make_pair(1, pi));
				pss = make_pair(pi, make_pair(0, pi));


			} else {
				// prs = make_pair(pi-1, make_pair(1, pi));
				prs = make_pair(pi, make_pair(0, pi));

				pss = make_pair(x - pi, make_pair(pi, x));
			}
		} else {
			pair<ll, pair<ll, ll> > top = pq.top();
			if (pi >= top.second.first && pi <= top.second.second) {
				pq.pop();
				prs  = make_pair(pi - top.second.first, make_pair(top.second.first, pi));
				pss = make_pair(top.second.second - pi, make_pair(pi, top.second.second));
			} else if (pi < top.second.first){
				prs = make_pair(top.second.first-pi, make_pair(pi, top.second.first));
			} else {
				prs = make_pair(pi - top.second.second, make_pair(top.second.second, pi));
			}
		}

		pq.push(prs);
		pq.push(pss);

		auto curr = pq.top();

		ans[i] = curr.first;
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
}