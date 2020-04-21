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
#define forminus(i,n) \
for(int i = (n)-1; i>=0 ;--i)
#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define REPLess(i,a,b) \
for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

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
int N;
int main() {
cin >> N;
int arr[N];
forn(i, N) cin >> arr[i];

//forn(i, N-5) {
//	REPLess(j, i+1, N-4) {
//		REPLess(k, j+1, N-3) {
//			REPLess(l, k+1, N-2) {
//				REPLess(m, l+1, N-1) {
//					REPLess(o, m+1, N) {
//						printf("%d %d %d %d %d %d\n", arr[i],arr[j],arr[k],arr[l],arr[m],arr[o]);
//					}
//				}
//
//			}
//		}
//	}
//}
forn(i, N-5) {
	REP(j, i+1, N-5) {
		REP(k, j+1, N-4) {
			REP(l, k+1, N-3) {
				REP(m, l+1, N-2) {
					REP(o, m+1, N-1) {
						printf("%d %d %d %d %d %d\n", arr[i],arr[j],arr[k],arr[l],arr[m],arr[o]);
					}
				}

			}
		}
	}
}



return 0;
}
