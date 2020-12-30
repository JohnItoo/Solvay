//============================================================================
// Name        : template.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
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
	ios::sync_with_stdio(false);
	cin.tie(0);
    int tc; cin >> tc; 
    while(tc--) {
        string s; cin >> s;
        int n = s.length();
        int three = 0;
        int two = 0;
        map<int, int> mp;
        int ii = 0;
        while(ii <= n-3) {
         if(s[ii] == s[ii+1] && s[ii+1] == s[ii+2]) {
             mp[ii]++;
             mp[ii+1]++;
             mp[ii+2]++;
             three++;
             ii+=3;
             continue;
         }
         ii += 1;
        }
          int aux = 0;
        REP(i, 1, n-2) {
        //   if(mp.find(i) != mp.end()  || mp.find(i-1) != mp.end() ||  mp.find(i+1) != mp.end()) continue;
        if(mp.find(i-1) != mp.end()) continue;
           if(s[i+1] == s[i-1]) {
            //   mp[i] = 1;
                mp[i+1] = 1;
             //  mp[i-1] = 1;
               aux++;

           }
        }
        //int i = 0;
        forn(i, n-1) {
            if(mp.find(i) != mp.end() || mp.find(i+1) != mp.end()) continue;
            if(s[i] == s[i+1]) {
                mp[i] = 1;
                mp[i+1] = 1;
                two++;
            }
        }
      
        // cout << aux << " aux\n";
        cout << (three * 2) + two  + aux << endl;
    }
	return 0;
}
