#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	map<string, int> mp;
	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		mp[s]++; 
	}
	int mx = 0;
	string res = "";
	for(auto ii : mp) {
		string key = ii.first;
		if(mp[key] > mx) {
			mx = mp[key];
			res = key;
		}
	}

	cout << mx << "\n";

	return 0;
}