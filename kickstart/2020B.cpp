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

int sol = 0;
int grid[55][35];
int dne[55];

string trUpp(string s) {
	
  	transform(s.begin(), s.end(), s.begin(), ::toupper);
 return "";
}
// sorts with second in descending order and if second is equal sorts with first if descending order
bool sortPairs(ii &a,  ii &b) {
	if(a.second == b.second) return a.first > b.first;
	else return a.second > b.second;
}

void bktrk(int left, int strt,  int tkn, int trgt, int sum, int n, int k) {
	if( tkn == trgt)  {
       sol = max(sol, sum);
       return;
	}
	if(left == 1) {
		sol = max(sol, sum + grid[strt][trgt-tkn]);
		return;
	}

	REP(i,1, n) {
		if(i == strt) continue;
		//take j plates from ith stack
		REP(j , 0, k) {
			bktrk(left -1, i, j +tkn, trgt, sum + grid[i][j], n, k);
		}
	}
}

void solve() {
	int n ,k,p; cin >> n >> k >> p;
	memset(dne, 0, sizeof dne);
	REP(i, 1,n) {
		REP(j, 1, k) {
			int x ; cin >> x;
			if(j == 1) grid[i][j] = x;
			else grid[i][j] = grid[i][j-1] + x;
		}
	}

	REP(i,1, n) {
		//take j plates from ith stack
		REP(j , 0, k) {
			bktrk(n- 1, i, j, p, grid[i][j], n, k);
		}
	}
       cout << sol << endl;
      sol = 0;
	
}

int main() {
	int tc ; cin >> tc; 
	forn(i, tc) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
return 0;
}
