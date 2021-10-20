#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n;
  cin >> n;
  ll x;
 cin >> x;
 vector<ll> a(n);
 for(int i = 0; i < n; i++) {
 	cin >> a[i];
 }
 map<ll, pair<int, int> > mp;
 for(int i = n-1; i >= 0; i--) {
 	for(int j = i-1; j >= 0; j--) {
 		ll rem = x - a[i] - a[j];
 		if(mp.find(rem) != mp.end()) {
 			pair<int, int> idxs = mp[rem];
 			cout << i+1 << " " << j+1 << " " << idxs.first +1 << " " << idxs.second +1 << endl;
 			return 0;
 		}
 	}
 	
 	for(int j = i+1; j < n; j++) {
 		mp[a[i] + a[j]] = {i, j};
 	}
 }
 cout << "IMPOSSIBLE\n";

  return 0;
}