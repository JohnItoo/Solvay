#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main() {
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
	int n; cin >> n;

	vector<int> perm(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> perm[i];
	}

	vector<ll> strings(n+1);

	for(int i = 1; i <= n; i++) {
		cin >> strings[i];
	}

	vector<ll> result(n+1);

	for(int i = 1; i <= n; i++) {
		result[i] = perm[perm[perm[i]]];
	}

	for(int i = 1; i <= n; i++) {
		ll id = strings[result[i]];
		cout << id << "\n";
	}

	return 0;
}