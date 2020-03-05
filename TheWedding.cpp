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
int TR[20][20],RH[20][20], HT[20][20];

int main() {
	string first;
	//
	//  getline(cin, first);
	int t,r,h = 0;
	cin >> t >> r >> h;

	forn(i,t) {
		forn(j,r+1) {
			cin >> TR[i][j];
		}
	}

	forn(i,r) {
		forn(j,h+1) {
			cin >> RH[i][j];
		}
	}

	forn(i,h) {
		forn(j,t+1) {
			cin >> HT[i][j];
		}
	}
	int price = 0;
	int bestPrice = 10000000;
	int res, hotel, tr = 0;
	forn(i,t) {

		forn(j,r+1) {

		         if(!TR[i][j] && i > 0) {
		        	 forn(k, h+1) {
		        		 if(!RH[j][k] && !HT[k][i] && k>0 && (TR[i][0] + RH[j][0] + HT[k][0] < bestPrice)) {
		        			 bestPrice = TR[i][0] + RH[j][0] + HT[k][0];
		        			 res = j; tr= i; hotel = k;
		        		 }
		        		 bestPrice = 10000000;
				}

			}

		}


	}

	if (bestPrice == 10000000) {
		cout << "Do Not get Married";
	} else {
		printf("%d %d %d : %d", tr, res, hotel, bestPrice);
	}




}
