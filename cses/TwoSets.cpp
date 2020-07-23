#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	unsigned long long int sum = (n * (n + 1)) / 2;
	cout << "This is sum " << sum << "\n";
	if ((sum % 2 != 0 ) ) {
		cout << "NO\n";
	} else {
		vector<long long> a;
		vector<long long> b;
		map<long long, int> marked;
 		unsigned long long int s = sum / 2;
      unsigned long long  int t = n;
      unsigned long long int curr = 0;
      unsigned long long int last = n;
       cout << s << "\n";
       while(t + curr <= s) {
          a.push_back(t);
          curr += t;
          marked[t] = true;
          cout << "this is t ; " << t << "\n";
          last = t;
          t--;
       } 

       if(s > curr) {
       	 a.push_back(s-curr);
       	 marked[s-curr] = 1;
       	 cout << "this is t ; " << s - curr << "\n";

       }

      //  for(int i = 1; i <=n; i++) {
      //  	if(marked[i]) continue;
      //  	b.push_back(i);
      //  }
      
      // cout << "YES\n";
      // cout << a.size() << "\n";
      // for(int i = 0; i < a.size(); i++) {
      // 	cout << a[i] << " ";
      // }
      // cout << "\n";

      // cout << b.size() << "\n";
      // for(int i = 0; i < b.size(); i++) {
      // 	cout << b[i] << " ";
      // }
	}
}
