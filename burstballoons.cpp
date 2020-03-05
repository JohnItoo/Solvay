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

int check(vi vec) {
    vec.insert(vec.begin(), 1);
    vec.push_back(1);
    int dp[vec.size()][vec.size()];
    memset(dp, 0, sizeof dp);
    
    for(int L = 0; L<=vec.size()-1; ++L) {
        for(int R=0; R<=vec.size()-1; ++R) {
            int sol = 0;
         for(int i = L+1; i<= R-1; ++i) {
               sol = max(sol, dp[L][i] + dp[i][R] + (vec[L] * vec[i] * vec[R]));
            }
            dp[L][R] = sol;
        }
    }

    for(int i = 0; i<vec.size(); ++i) {
        cout << "\n";
        for(int j = 0; j<vec.size(); ++j) {
            cout << dp[i][j] << " ";
        }
    }
    return 0;

}
int main() {
    vi n;
    n.pb(3); n.pb(1); n.pb(5); n.pb(8);
    check(n);
return 0;g
}
