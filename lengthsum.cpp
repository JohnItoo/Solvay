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
#include <string.h>
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
int m, s, dpmin[100][900], dpmax[100][900];
int INF_VALUE = 2139062143;

bool canFly(int x, int j, int i) {
    int div = 10;
    int sum = 0;
    int ct = 0;
   while(x >= 1) {
      sum += x % div;
       x /= 10;
       ct++; // tries to catch 1. Ensures that count is equal to what is needed.
   }
   return j == sum && i == ct;
}
int main() {
 cin >> m >> s;
 memset(dpmin, MEMSET_INF, sizeof dpmin);
 memset(dpmax, -1, sizeof dpmax);

 for(int i = 0; i<=9; ++i) {
     dpmin[1][i] = i;
     dpmax[1][i] = i;
 }
 for(int i = 2; i <= m; i++) {
     for(int j = 1; j <= s; j++) {
        //  if(i > j ) continue;
         for(int x = 0; x<=j; ++x ) {
        // cout << dpmin[i-1][j-x] << " m - i * 10 " << (1-1) * 10  << "\n";
        // int fact = m == i ? 1 : (m - i) * 10;
        int fact = (i - 1) * 10;
        if(dpmin[i-1][j-x] ==  2139062143 ) continue;
        int temp = dpmin[i-1][j-x] * fact + x;
        // cout << "dpmin[i-1][j-x] == " << dpmin[i-1][j-x] << "\n"; 
                // cout << "dpmin[i-1][j-x] == " << dpmin[i-1][j-x] << "\n"; 

        if( temp < dpmin[i][j] && canFly(temp , j, i )) {
            // cout << "flown" << "\n";
           dpmin[i][j] = temp;
        }
        if(temp > dpmax[i][j] && canFly(temp , j, i )) {
           dpmax[i][j] = temp;
        }
        //    cout << dpmin[i][j] << " " << i << " i and j " << j << " " << x << "\n";
      }
     }
 }
 int solMin = dpmin[m][s] ==  2139062143 ? -1 : dpmin[m][s];
  cout << solMin << " " << dpmax[m][s];

// cout << canFly(2356, 17);

return 0;
}
