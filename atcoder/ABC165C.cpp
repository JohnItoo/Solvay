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
struct st {
 int a; 
 int b; int c; int d;
 st(int a, int b, int c, int d) {
 	this->a = a; 
 	this->b= b;
 	this->c= c;
 	this->d = d;
 }
};
bool comp(st a, st b) {
	return a.d > b.d;
}

int main() {
	ios::sync_with_stdio(false);
 cin.tie(0);
 int n, m, q; cin >> n >> m >> q;
 vector<st> vsst;
 forn(i, q) {
 	int a, b, c, d; cin >> a >> b >> c >> d;
 	st nst = st(a,b,c,d);
 	vsst.pb(nst);
 }
 sort(vsst.begin(), vsst.end(), comp);
 int arr[n];  
 forn(i, vsst.size()-1) {
 	memset(arr, 0, n);
 	REP(j, i+1, vsst.size()-1) {
        st s = vsst[j];
        if(arr[s.b -1] != 0 && arr[s.a-1] != 0 && arr[s.b-1] - arr[s.a-1] != s.c) continue;
        if(arr[s.b-1] == 0) {
        	arr[s.b-1] =  
        }
 	}

 }

return 0;
}
