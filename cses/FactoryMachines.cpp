#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll n, t; cin >> n >> t;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

    ll mx = a[0] * t;

    ll low = 1;
    ll high = mx;
    ll ans = 0;

    while(low <= high) {
    	ll mid = (high + low) / 2;
    	ll ct = 0;
    	for(int i = 0; i < n; i++) {
    		 ct += ( mid / a[i]);
    	} 
    	if(ct < t) {
    		low = mid + 1;
    	} else {
    		high = mid - 1;
    		ans = mid;
    	}
    }
    cout << ans << endl;
   return 0;

}