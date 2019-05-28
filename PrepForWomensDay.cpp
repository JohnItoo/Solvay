//============================================================================
// Name        : PrepForWomensDay.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#define val 200000
using namespace std;

int n,k,d[val];

int main() {
	scanf("%d%d", &n, &k);

	for(int i = 1; i <= k; ++i) scanf("%d", &d[i]);

	bool picked[k];
	int ans = 0;

	for(int i = 1; i < n; ++i) {
		cout << "in loop \n";
//		if(picked[i]) continue;
		for (int j = i + 1; j<= n ; ++j) {
			if(picked[j]) continue;
			if(d[i] + d[j] % k == 0) {
				picked[i] =true;
				picked[j] = true;
				ans+=2;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
