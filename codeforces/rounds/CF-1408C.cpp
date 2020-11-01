//============================================================================
// Name        : template.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <set>
#include <vector>
#include <string.h> // for memset in CF judge.
using namespace std;
#define _CRT_SECURE_NO_DEPRECATE // suppress some compilation warning messages (for VC++ users)
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
// To simplify repetitions/loops, Note: define your loop style and stick with it!
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define forn(i,n) \
for (int i =0; i<(n); i++)
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000 // 2 billion
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); // useful to clear array of integers

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	while (tc--) {
		int n; double l; cin >> n >> l;
		vector<double> flags(n);

		forn(i, n) cin >> flags[i];

		int i = 0;
		int j = n - 1;
		double presa = 0;
		double presb = l;
		double speeda = 1;
		double speedb = 1;
		double totaltime = 0;
		int lastmove = 8;
		while (i < j) {

			double dista = flags[i] - presa;
			double timea = dista / speeda;

			double distb = presb - flags[j];
			double timeb = distb / speeda;


			// printf("% .2f  %.2f\n" , timea, timeb);

			if (timea == timeb) {
				speeda += 1;
				speedb += 1;
				presa = flags[i++];
				presb = flags[j--];
				totaltime += timea;
				lastmove = 0;
			} else {
				if (timea < timeb) {
					presa = flags[i++];
					presb -=  (timea * speedb);
					speeda += 1;
					totaltime += timea;
					lastmove = 1;
				} else {
					presb = flags[j--];
					presa += (timeb * speeda);
					speedb += 1;
					totaltime += timeb;
					lastmove = -1;
				}
			}
		}
		double freshtime = 0;
		if (i == j || lastmove == 0) {
			lastmove = flags[i] - presa > presb - flags[i] ? 1 : -1;
		}
		if (lastmove == 1) {
			double distflag = presb - flags[j];
			freshtime = distflag / speedb;
			presb = flags[j];
			speedb += 1;
			presa += (freshtime * speeda);
		} else if (lastmove == -1) {

			double distflag = flags[i] - presa;
			freshtime = distflag / speeda;
			presa = flags[i];
			speeda += 1;
			presb -= (freshtime * speedb);
		}
		// printf("% .2f \n", freshtime);

		totaltime += freshtime;
		double meet = ((speeda * presb) + (speedb * presa)) / (speeda + speedb);
		double rem = meet - presa;
		double tmmeet =  rem / speeda;

		printf("% .16f \n" , tmmeet + totaltime);

	}
	return 0;
}
