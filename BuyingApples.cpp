//============================================================================
// Name        : BuyingApples.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : https://www.spoj.com/problems/ABA12C/
//============================================================================

#include <iostream>
#include <algorithm>
#define INF 1000000007

int price[1005],b,f,idx;
using namespace std;

int main() {
	scanf("%d", &idx);
	while (idx > 0) {
	scanf("%d%d", &b, &f);
	int dp[f + 1];
	dp[0] = 0;
	for(int i = 1; i <=f; ++i) {
		scanf("%d", &price[i]);
		dp[i] = INF;
	}

	for(int w = 1; w <= f; ++w) {
		for(int kg = 1; kg <= f + 1; ++kg) {
			if(price[kg] == -1) continue;
			if(w - kg >= 0) {
				dp[w] = min(dp[w], dp[w-kg] + price[kg]);
			}
		}
	}

	int sol;
	if(dp[f] == INF) sol = -1;
	else sol = dp[f];
	printf("%d\n",sol);
	idx -= 1;
	}

	return 0;
}
