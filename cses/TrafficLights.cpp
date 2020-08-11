#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	// int x;
	// cin >> x;
	// int n; cin >> n;
	// set<int> s;
	// multiset<int> ms;
	// s.insert(0);
	// s.insert(x);


	// for (int i = 0; i < n; i++) {
	// 	int pi; cin >> pi;
	// 	auto l = s.lower_bound(pi), r = --s.upper_bound(pi);

	// 	if (*l > pi) --l;
	// 	if (*r < pi) ++r;

	// 	if (ms.find(*r - *l) != ms.end()) ms.erase(ms.find(*r - *l));

	// 	ms.insert(pi - *l);
	// 	ms.insert(*r - pi);
	// 	s.insert(pi);


	// 	cout << *--ms.end() << " ";
	// }

	int x, n, a[200002];
	set <int> s;
	multiset <int> m;
	cin >> x >> n;
	s.insert(0);
	s.insert(x);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		auto l = s.lower_bound(a[i]), r = --s.upper_bound(a[i]);
		if (*l > a[i]) --l;
		if (*r < a[i]) ++r;
		auto f = m.find(*r - *l);
		if (f != m.end()) m.erase(f);
		m.insert(a[i] - *l);
		m.insert(*r - a[i]);
		s.insert(a[i]);
		cout << *--m.end() << ' ';
	}

}