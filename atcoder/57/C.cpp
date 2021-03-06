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
double sm;
int ans;
void backtrack(int v[], int lef, vi em, int sel[], int n) {
   if(lef ==0) {
     double curr = 0;
     for(int x : em) curr+= x;
     double avg = curr /em.size();
 cout << "this is avg " << avg << endl;
     if(sm == avg)  ans++;
   	return;
   }
    for(int i = 0; i <n; i++) {
        if(sel[i] == 1) continue;
        em.pb(v[i]);
        sel[i] = 1;
        backtrack(v, lef-1, em, sel, n);
        em.pop_back();
        sel[i] = 0; 
    }
}

int main() {
	int n,a,b; 
	cin >> n >> a >> b;
	int v[n];
	forn(i,n) cin >> v[i];

	sort(v, v+n);
	double tot = 0; double gu = a;
	for(int i = 0; i<a; i++) {
       tot += v[n-1-i];
	}
	sm = tot/a;

   for(int i = a; i<=b; i++) {
   	vi em; int sel[n];
   	backtrack(v, i, em, sel, n);
   }
cout << sm << endl;
cout << ans << endl;
return 0;
}
