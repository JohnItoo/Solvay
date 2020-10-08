#include <bits/stdc++.h>
using namespace std;
int main () {
	int n,k; cin >> n >> k;

	vector<vector<int> > g(n, vector<int>(n));

	int front = 1;
	int back = n*n;
	long long ans = 0;

	for(int row = 0; row < n; row++) {
		for(int col = 0; col < k-1; col++) {
			g[row][col] = front;
			front+= 1;
		}

		for(int col = n-1; col >= k-1; col-- ) {

			g[row][col] = back;
			if(col == k-1) ans += back;
			back -= 1;
		}
	}


    cout << ans << "\n";
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << g[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}