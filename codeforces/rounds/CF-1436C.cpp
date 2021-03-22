// Problem: C. Binary Search
// Contest: Codeforces - Codeforces Round #678 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1436/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//============================================================================
// Name        : template.cpp
// Author      :   $%U%$   
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
#define _CRT_SECURE_NO_DEPRECATE  // suppress some compilation warning messages
                                  // (for VC++ users)
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
// To simplify repetitions/loops, Note: define your loop style and stick with
// it!
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define REP(i, a, b) \
    for (int i = int(a); i <= int(b); i++)  // a to b, and variable i is local!
#define forn(i, n) for (int i = 0; i < (n); i++)
#define TRvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000  // 2 billion
// If you need to recall how to use memset:
#define MEMSET_INF 127      // about 2B
#define MEMSET_HALF_INF 63  // about 1B
// memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path
// distances memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP
// memoization table memset(arr, 0, sizeof arr); // useful to clear array of
// integers
ll mod = 1e9 + 7;

ll C(ll n, ll k) {
    ll res = 1;
    for (int i = n - k + 1; i <= n; ++i)
        res *= i;
    for (int i = 2; i <= k; ++i)
        res /= i;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, x, pos; cin >> n >> x >> pos;
    ll spaceleft = pos-1;
    ll spacert = n-pos;
    ll greater = n - x;
    ll less = x-1;
    cout << spaceleft << " " << spacert << " " << greater << " " << less << "\n";
    ll greatrt = C(greater, spacert);
    cout << greatrt << " ";
   // greatrt %= mod;
    ll lessrt = C(less, spacert);
    cout << lessrt << " ";
  //  lessrt %= mod;
    
    ll greatlft = C(less, spaceleft);
    cout << greatlft << " ";
  //  greatlft %= mod;
    ll lesslft = C(greater, spacert);
    cout << lesslft << " \n";
  //  lesslft %= mod;
    ll ans = greatrt + lessrt + greatlft + lesslft;
    cout << ans << endl;
    
    return 0;
}
