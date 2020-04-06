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

//https://codeforces.com/problemset

int main() {
    int Tc;
    cin >> Tc;
    while(Tc--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;

        int left = 0; int right = 0; int  up = 0; int down = 0;
          
        if(x > 0) {
            
            left = (x) * (b); 
            // cout << "left is " << left << "\n"; // x - 1 + 1 -0
        }
        if(x < a-1) {
            right = (a-(x + 1)) * b;
            //  cout << "rt is " << right << "\n";
        }
        if(y > 0) {
            up = (y) * a;
            //  cout << "up is " << up<< "\n";
        }
        if(y < b-1) {
            down = (b-(y + 1)) * a;
            //  cout << "dwn is " << down << "\n";
        }
        int sol = 0;
        // cout << sol << " previous soll \n";
        sol = max(max(left, right), max(up, down));
       cout << sol << "\n";
    }
return 0;
}
