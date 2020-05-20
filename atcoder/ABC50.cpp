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
const int MOD = 1e9+7;

int A() {
    int a , b; string c;
    cin >> a >> c >> b;
    if(c == "+")  cout << a + b;
    else cout << a - b;
return 0;
}
int B() {
    int N; cin >> N;
    int t[N];
    forn(i, N) cin >> t[i];
    int m; cin >> m;
    while(m--) {
        int p, x;
        cin >> p >> x;
        int sum = 0;
        for(int i  = 1; i <= N; i++) {
            if(i==p) sum += x;
            else sum += t[i-1];
        }
        cout << sum << "\n";
    }
    return 0;
}
//C
int main() {
    int n; cin >> n;
    int a[n+2];
    forn(i, n) {
  int p = 0; cin >> p;
       a[p]++;
    }
    
    int ans = 1;
    if(n % 2 == 1) {
        if(a[0] != 0 ) cout << 0 << endl; return 0;
        for(int t = 1; t <n; t++)
         if(a[t] != 2) cout << 0 << endl; return 0;
          (ans *= 2) %= MOD;
        cout << ans << endl;
    } else {
       for(int t = 1; t <n; t++)
         if(a[t] != 2) cout << 0 << endl; return 0;
         (ans+=ans * 2) %= MOD;
      cout << ans << endl;
    }
}