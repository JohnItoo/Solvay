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
#include <math.h>
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
    int n, k;
    int s;

    cin >> n >> k;
    cin >> s;

    string nt = to_string(s);

    if(nt.length() == 1) {cout <<0; return 0;}

    int idx = 0;
    int ans = 0;
    vector<int> vc(n);

    for(int i=0; i <nt.length(); ++i) {
        int ai = nt[i] - '0';
        vc[i] = ai;
    }

    for(int i=0; i <nt.length(); ++i) {
        int ai = nt[i] - '0';
        if(ai >0 && i > 0 && idx < k) {
            vc[i] = 0;     
               idx++;     
        } else if(ai > 0  && i == 0 && idx < k) {
            vc[i] = 1;
               idx++;
        }
  
    }

    int sum = 0;

    for(int i = 0; i<nt.length(); ++i) {
        //   int ai = vc[i] - '0'; 
        //   cout << vc[i] << "\n";
        // sum += pow (10, i) * ai;
        cout << vc[i];
    }
    // cout << sum;

return 0;
}
