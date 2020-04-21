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

int main() {
    vector<int> hrs = {6,9,9};
    int sz = hrs.size();
        if(sz == 1) {return hrs[0] > 8 ? 1 : 0;}
        vector<int> vi(sz);
        for(int i = 0; i<sz; ++i) {vi[i] = hrs[i] > 8 ? 1 : -1;}
        bool sn = false;
        int lnt = 0; int lsSt = 0; int sol = 0;
        for(int j = 0; j< sz ; ++j) {
            if(vi[j] == 1) {
                lnt++;
                sn = true;
            } else {
                if(sn) {
                   if(lsSt + 1 < lnt) {
                       lsSt ++;
                   } else {
                       sol = max(sol, lsSt + lnt);
                       lsSt = 1;
                       lnt = 0;           
                   }
                } else {
                   lsSt = 1;
                }
            }
        }
        cout << sol;
        return 0;

}
