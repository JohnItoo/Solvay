#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	long long x;
	cin >> x;
	int n; 
	priority_queue<pair<ll, pair<ll, ll> > > pq;

	for(int i = 0; i < n; i++) {
		ll pi; cin >> pi;
		pair<ll, pair<ll, ll> > pr;
		if(i == 0) {
            if(x - pi > pi - 1) {
            	pr = make_pair(x-pi, make_pair(pi, x));
            } else {
            	pr 
            }
		}
	}
}