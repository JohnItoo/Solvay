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
int n, m;
int main() {
cin >> n >> m;

int mt [n][m];
int norm [n][m];
vector<pair<int,int> > vp;
for(int i = 0; i <n; ++i) {
   for(int j = 0; j <m; ++j) {
       cin >> mt[i][j];
       norm[i] [j] = 0;
   }
}

for(int i = 0; i <n-1; ++i) {
   for(int j = 0; j <m-1; ++j) {
    if(mt[i][j] && mt[i+1][j] && mt[i][j+1] && mt[i+1][j+1]) {
        norm[i][j] = norm[i+1][j] = norm[i][j+1] = norm[i+1][j+1] = 1;
        vp.pb(mp(i+1,j+1));
    }
   }
}

for(int i = 0; i <n; ++i) {
   for(int j = 0; j <m; ++j) {
      if(mt[i][j] && !norm[i][j]) { cout << -1; return 0;} 
   }
}
cout << vp.size() << "\n";

for(int i = 0; i<vp.size(); ++i) {
    cout << vp[i].first << " " << vp[i].second << "\n";
}

return 0;
}
