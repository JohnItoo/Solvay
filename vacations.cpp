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
int x, a[100];
int dp[100][3];
int main() {
   cin >> x; 
   forn(i, x) { cin >> a[i]; dp[i][0] = dp[i][1] = dp[i][2] = 1000; }

   dp[0][0] = 1;
   if(a[0] == 1 || a[0] == 3) { dp[0][1] = 0;}
   if(a[0] == 2 || a[0] == 3) { dp[0][2] = 0;}


   for(int i = 1; i<x; i++) {
       dp[i][0] = 1 + min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]));
       if(a[i] == 1 || a[i] == 3) { dp[i][1] = min(dp[i-1][0], dp[i-1][2]); } 
       if(a[i] == 2 || a[i] == 3) { dp[i][2] = min(dp[i-1][0], dp[i-1][1]); }
   }

    for(int i = 0; i<x; i++) {
      cout << "\n";
      cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2];
   }
cout <<  min(dp[x-1][0], min(dp[x-1][1], dp[x-1][2]));
}
