// Problem: Reading Books
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1631
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//============================================================================
// Name        : BXK
// Author      : Template
// Version     :
// Copyright   : Who was here
// Description : Hello World in C++, Ansi-style
//============================================================================
//TODO Bits/stdc++.h on diff machine
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <set>
#include <vector>
#include <string.h> // for memset in CF judge.
#include <numeric>
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
void solve() {
 int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.rbegin(), a.rend());
    if (n == 1) {
        cout << a[0] * 2 << endl;
        return;
    }
    ll sm = accumulate(a.begin(), a.end(), 0LL);
    ll left = 0;
    ll right = 0;
    int i = 0;
    int tm = 0;
    while (i < n) {
        ll currL = a[i];
        int j = i + 1;
        ll currR = 0;
        tm++;
        while (j < n && currR < currL) {
            currR += a[j++];
        }
        left += currL;
        right += currR;
        i = j;
    }
    ll ans = 0;
  //  cout << tm << " tm ";
    if (tm == 1 && n > 3) {
      ans = max(left,right) * 2;
    } else {
       ans = left + right;
       
    }
    // if(ans > sm * 2) {
       	// ans = sm*2;
    // }
    cout << ans <<endl;
 
    return;
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
int tc = 1;
//cin >> tc;
int count = 1;
while(tc--) {

 //cout << "Case #" << count << ": "; //CODEJAM/KICKSTART
 count++;
 solve();
}
return 0;
}
