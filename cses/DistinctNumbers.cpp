#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	map<long long , int> a;
	int count = 0;
	for(int i = 0; i < n; i++) {
		long long x; cin >> x;
      if(a.find(x) == a.end()) {
      	a[x] = 1;
      	count++;
      }
	}
	cout << count << "\n";
}