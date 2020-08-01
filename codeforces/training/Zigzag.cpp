#include <bits/stdc++.h>
using namespace std;


int main() {

  int n; 
  cin  >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
  	 cin >> a[i];
  }
  vector<vector<int> > dp(n+1, vector<int>(2, 0));
  dp[0][0] = 1;
  dp[0][1] = 1;

  int best = 1;
  for(int i = 1; i < n; i++) {
  	for(int j = 0; j < i ; j++) {
  		if(a[j] < a[i]) dp[i][0] = max(dp[j][1] + 1, dp[i][0]);
  		else if (a[j] > a[i]) dp[i][1] = max(dp[j][0] + 1, dp[i][0]);
  	}
  	best = max(dp[i][0], dp[i][1]);
  }

  cout << best << "\n";
}

//This solution is dp but it is crude.
int unused() {
	int n;
	cin >> n;
	int a[n + 1];
	int prev[n + 1];
	int dp[n + 1];
	vector<int> vi;
	map  <int, int > mps;


	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i > 1) prev[i] = i - 1;
		else prev[i] = 1;
		dp[i] = 2;
		if (mps.find(a[i]) == mps.end()) {
			mps[a[i]] = 1;
			vi.push_back(a[i]);
		}
	}
	if (vi.size() < 2) {
		cout << 1 << "\n";
	} else {
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (a[prev[j]] < a[j] && a[j] > a[i]) {
					if (dp[i] < dp[j] + 1) {
						prev[i] = j;
						dp[i] = dp[j] + 1;
					}
				} else if (a[prev[j]] > a[j] && a[j] < a[i]) {
					if (dp[i] < dp[j] + 1) {
						prev[i] = j;
						dp[i] = dp[j] + 1;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			cout << dp[i] << " ";
		}
	}
	// prev[2] = 1;


	cout << "\n";
	cout << dp[n] << "\n";
	return 0;
}