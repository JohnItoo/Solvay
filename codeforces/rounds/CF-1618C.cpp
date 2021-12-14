// Problem: C. Paint the Array
// Contest: Codeforces - Codeforces Round #760 (Div. 3)
// URL: https://codeforces.com/contest/1618/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//============================================================================
// Name        : BXK
// Author      : Template
// Version     :
// Copyright   : Who was here
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

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
void solve() {
 int n; cin >> n;
 vector<ll> a(n);
 forn(i, n) {
 	cin >> a[i];
 }
 ll fir = a[0];
 
 for(int i = 2; i < n; i+=2) {
 	fir = gcd(fir, a[i]);
 }
 ll sec = a[1];
 
 for(int i = 3; i < n; i += 2) {
 	sec = gcd(sec, a[i]);
 }
 bool firvald = true;
 for(int i = 1; i < n; i+=2) {
 	if(a[i] % fir == 0) {
 		firvald = false;
 		break;
 	}
 }
 bool secvald = true;
 for(int i = 0; i < n; i+= 2) {
 	if(a[i] % sec == 0) {
 		secvald = false;
 		break;
 	}
 }
 if(firvald) {
 	cout << fir <<endl;
 } else if(secvald){
 	cout << sec <<endl;
 } else {
 	cout << 0 <<endl;
 }
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
int tc = 1;
cin >> tc;
int count = 1;
while(tc--) {

 //cout << "Case #" << count << ": "; //CODEJAM/KICKSTART
 count++;
 solve();
}
return 0;
}
