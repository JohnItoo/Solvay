//============================================================================
// Name        : completeSearchToDp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int memo[215][25], price[25][25],score,M,C,K;

int shop(int money, int id) {
	if(money < 0) return -1000000;
	if(id == C) return M - money;
	if(memo[money][id] != -1 ) return memo[money][id];
	int best = -1000000;
	for(int i =1; i<= price[id][0]; ++i) {
		best = max(best, shop(M - price[id][i], id+1));
	}
	return memo[money][id] = best;// we are actually saving the state of this function instead of checking the recursive call we c
}

int main() {
 int TC,i,j;
 cin >> TC;
 while(TC--) {
	 scanf("%d %d", &M, &C);
	 for (i = 0; i < C; i++) {
	 scanf("%d", &K);
	 price[i][0] = K; // to simplify coding, we store K in price[i][0]
	 for (j = 1; j <= K; j++)
	 scanf("%d", &price[i][j]);
	 }
	 memset(memo, -1, sizeof memo); // initialize DP memo table
	 score = shop(M, 0); // start the top-down DP
	 if (score < 0)
	 printf("no solution\n");
	 else
	 printf("%d\n", score);
	 }
	 }
