#include <bits/stdc++.h>
using namespace std;
int n = 0;
vector<char> permutation;
vector<bool> picked(8, false);
vector<string> result;
string st;
map<string, int> mp ;
void search() {
	if (permutation.size() == n) {
		string ans = "";
		for (int i = 0; i < n ; i++) {
			ans.push_back(permutation[i]);
		}
		if (mp.find(ans) == mp.end()) {
			result.push_back(ans);
			mp[ans] = 1;

		}
	}
	else {

		for (int i = 0; i < n; i++) {
			if (picked[i]) continue;
			picked[i] = true;

			permutation.push_back(st[i]);
			search();
			picked[i] = false;
			permutation.pop_back();
		}
	}
}

int main() {
	cin >> st;
	n = st.length();
	search();

	cout << result.size() << "\n";
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
}