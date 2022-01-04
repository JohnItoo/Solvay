// Problem: Your Ride Is Here
// Contest: USACO - Training
// URL: https://train.usaco.org/usacoprob2?a=bv2CGIXpml6&S=ride
// Memory Limit: 16 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: itoohue1
PROG: ride
LANG: C++                 
*/
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
freopen("ride.in", "r", stdin);
 freopen("ride.out", "w", stdout);
string x, y; cin >> x >> y;
int xprod = 1;
int yprod = 1;
forn(i, x.size()) {
	xprod *= ((x[i] - 'A') + 1);
}
forn(i, y.size()) {
	yprod *= ((y[i] - 'A') +1);
}
if(xprod % 47 == yprod % 47) {
	cout << "GO\n";
} else {
	cout << "STAY\n";
}
return 0;
}
