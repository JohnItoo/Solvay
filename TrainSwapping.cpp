//============================================================================
// Name        : TrainSwapping.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;
int T,n, arr[50],swps;

int main() {
	scanf("%d", &T);
	getchar();
	while(T--) {
	scanf("%d", &n);
	swps = 0;

	for(int i = 0; i< n; ++i) {
		scanf("%d", &arr[i]);
	}

	for(int i = n-1; i >= 0; --i) {
		for(int j = n-i-1; j>= 0; j--) {
			if(arr[j-1] > arr[j]) {
				int temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
				swps++;
			}
		}
	}
	printf("Optimal train swapping takes %d swaps\n",swps);
	}
	return 0;
}
