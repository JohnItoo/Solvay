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
 int n, m;
  cin >> n >> m;
  int a[n][n]; int b[m][m];
  for(int i =0;i<n;i++) {
    string s; cin >> s;
    for(int j =0;j<n;j++) {
      if(s[j] == '#') a[i][j] =1;
      else a[i][j] = 0;
    }
  }
  
    for(int i =0;i<m;i++) {
    string s; cin >> s;
    for(int j =0;j<m;j++) {
      if(s[j] == '#') b[i][j] =1;
      else b[i][j] = 0;
    }
  }
  
          bool fnd = true;

   for(int i = 0; i<n; i++) {
     for(int j = 0; j<n; j++) {
        int x = b[0][0];
       if(x != a[i][j]) continue;
       for(int q = 0; q< m; q++) {
          for(int c = 1; c<m; c++) {
             if(b[q][c] != a[i+q][j+c]) {
               fnd = false;
               break;
             }
          }
         if(fnd) break;
         else if(!fnd && i != n -1) {
           fnd = true;
           break;
         }
       }
        if(fnd) break;
     }
     string ans = fnd ? "Yes" : "No";
     cout << ans << endl;
     
   }
  return 0;
}