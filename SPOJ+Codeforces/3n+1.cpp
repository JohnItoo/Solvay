//============================================================================
// Name        : 3n+1.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <algorithm>
#define LL long long

using namespace std;

int main() {
	int i;
	int j;


	while (scanf("%d %d", &i, &j) != EOF) {
		int frst = i;
		int scd = j;
		if (frst > scd) {
			swap(frst, scd);
		}

		int ans = 0;
		int tms;

		for (int a = frst ; a <= scd; ++a) {
			unsigned int cyc = a;
			tms = 1;

			while (cyc != 1) {
				if (cyc % 2 == 1) {
					cyc = 3 * cyc + 1;
				} else {
					cyc /= 2;
				}
				tms++;
			}

			if (tms > ans) ans = tms;
		}

		printf("%d %d %d\n", i , j, ans);
	}
	return 0;
}
