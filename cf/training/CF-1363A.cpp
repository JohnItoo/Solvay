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
bool ans = false;

void calc(int a[], int i , int j, int x, int n) {
  int res = 0;
  int ct = 0;
  REP (k, j , n-1) {
  	if(k == i) continue;
  	if(ct == x) break;
    res += a[k];
    ct++;
  }
  if(ct == x && res % 2 != 0) ans = true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;

	while (t--) {
		ans = false;
		int n , x; cin >> n >> x;
		int a[n];
		forn(i, n) cin >> a[i];
		string res = "No";
		forn(i, n) {
			forn(j, n) {
				calc(a, i, j, x, n);

				calc(a, -1, j, x, n);
			}
			if (ans) {
				res = "Yes";
				break;
			}
		}
		cout << res << endl;
	}
	return 0;
}
