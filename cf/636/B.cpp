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
	int tc;
	cin >> tc;
	while(tc--) {
		int x; cin >> x;
		if(x == 2){cout << "NO" << endl; continue;}
		int n = x/2;
		int sol[x];
		int d = 0; int sm = 0;
		forn(i,n) {
			d+=2;
			sol[i] = d;
			sm += d;
		}
		sol[n] = 1; sm -= 1;
		int st = 1;
		REP(i,n+1, x-1) {
           if(i == x-1 && sm % 2 == 0) {
           	cout << "NO" << endl; break;
           } 

           if(i != x -1) {
           	  st += 2;
           	  sm -= st;
           	  sol[i] = st;
           	  continue;
           }
           sol[x-1] = sm;
           cout << "YES" << endl;
           forn(i, x) {
             cout << sol[i] << " ";
           }
           cout << endl;
           
		}
	}
return 0;
}