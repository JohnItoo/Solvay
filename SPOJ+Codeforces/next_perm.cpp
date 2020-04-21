//============================================================================
// Name        : next_perm.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int x[9], TC, a, b, lineCounter; // it is ok to use global variables in competitive programming
bool place(int queen, int row) {
	for (int prev = 1; prev <= queen - 1; prev++) // check previously placed queens
		if (x[prev] == row || (abs(x[prev] - row) == abs(prev - queen)))
			return false; // an infeasible solution if share same row or same diagonal
	return true;
}
void NQueens(int queen) {
	do {

	} while();
}
int main() {
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d", &a, &b);
		memset(x, 0, sizeof x);
		lineCounter = 0;
		printf("SOLN COLUMN\n");
		printf(" # 1 2 3 4 5 6 7 8\n\n");
		NQueens(1); // generate all possible 8! candidate solutions
		if (TC)
			printf("\n");
	}
	return 0;
}
