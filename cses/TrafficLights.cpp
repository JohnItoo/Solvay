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
	map<int, int> mp;
	mp[x] = 1;


	for (int i = 0; i < n; i++) {
		int pi; cin >> pi;
		auto it = s.upper_bound(pi);
		int r = *it;
		--it;
		int l = *it;

		--mp[r - l];

		if (!mp[r - l]) mp.erase(r - l);

		++mp[pi - l];
		++mp[r - pi];
		s.insert(pi);


		cout << (--mp.end())->first << " ";
	}


}