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
int ans = 0;
void go(int st[], int n) {
	if(n <=1) return;
	int id = 0; int i = 0;
	while(i<n -1) {
        if(st[i] <= n  && st[i+1] > n) {
        	id = i;
        	break;
        }
        if(i == n-1) id = i;
        i++;
	}
	ans++;
    go(st, n -st[i]);
}
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int n; cin >> n;
		ans = 0;
		int st[n+3];
		st[1] = 2;
		REP(i, 2, n) {
			st[i] += st[i-1] + ((i*2) + i-1);
		}
		// int dp[n]; dp[2] = 1;
		// REP(i,3,n) {
  //         REP(j, 1,n) { // in sum
  //         	if(i < st[j]) continue;
  //         	dp[i] = 

  //         }
		// }
		go(st, n);
		cout << ans << endl;

	}
return 0;
}
