#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

	ll n, m; cin >> n >> m;

    ll curr = 0;
    set<pair<ll, int> > moments;
	for(int i = 0; i < n; i++) {
		ll c, t; cin >> c >> t;
		curr += c*t;
		moments.insert(make_pair(curr, i+1));
	}


	for(int i = 0; i <  m; i++) {
		int c; cin >> c;
		auto it = moments.lower_bound(make_pair(c, 0));
		cout << (*it).second << "\n";
	}


	return 0;
}