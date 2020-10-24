#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("mowing.in", "r", stdin);
	// freopen("mowing.out", "w", stdout);
	int n; cin >> n;
	pair<int, int> pres = make_pair(0,0);
	map<pair<int, int>, int> mp;
	mp[pres] = 0;
	int time = 0;
	int ans = -1;

	for(int i = 0; i < n; i++) {
		string dir; int val;
		cin >> dir >> val;
		for(int j = 0; j <val; j++) {
			int x = pres.first;
			int y = pres.second;
			pair<int, int> newp = make_pair(0, 0);
			int newtime = time + j + 1;
			if(dir == "N") {
               newp = make_pair(x, y+1);
			} else if(dir == "S") {
				newp = make_pair(x, y-1);
			} else if (dir == "W") {
				newp = make_pair(x-1, y);
			} else {
				newp = make_pair(x+1, y);
			}
			if(mp.find(newp) != mp.end()) {
				if(ans == -1) ans = newtime - mp[newp];
			}
			mp[newp] = newtime;
			pres = newp;
		}

		time += val;
	}

	cout <<ans << endl;



	return 0;
}