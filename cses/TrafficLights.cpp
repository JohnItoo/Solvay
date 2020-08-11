#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int x;
	cin >> x;
	int n; cin >> n;
	set<int> s;
	multiset<int> ms;
	s.insert(0);
	s.insert(x); 


	for (int i = 0; i < n; i++) {
	   int pi; cin >> pi;
		auto l = s.lower_bound(pi), r = --s.upper_bound(pi);
		if(*l > pi) l--;
		if(*r < pi) r++;

		if(ms.find(*r - *l) != ms.end()) ms.erase(*r - *l);

		ms.insert(*r-pi);
		ms.insert(pi-*l);

		auto end = ms.end()--;

		cout << *end << " ";
		s.insert(pi);
	}
}