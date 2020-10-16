#include <bits/stdc++.h>
using namespace std;

int main() {

	//f(i) is the length of longest sequence ending at i;

	// f(0) = 0
	// f(1) = 1;
	// f(i) = for max(f1 to fi-1) + 1;


   int n; cin >> n;
   vector<int> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   vector<int> dp(n+5, 1);
   
   for(int i = 1; i <= n; i++) {
   	for(int j = 1; j < i; j++) {
   		if(a[j-1] >= a[i-1]) continue;
   		dp[i] = max(dp[i], dp[j]+1);
   	}
   }

   cout << (*max_element(dp.begin(), dp.end())) << "\n";


	return 0;
}