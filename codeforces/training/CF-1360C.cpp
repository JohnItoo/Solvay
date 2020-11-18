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
  int tc;
  cin >> tc;
  while(tc--) {
  	int n; cin >> n;
  	vi a(n);
  	set<int> evens;
  	map<int, int> every;
  	forn(i,n) {
  		cin >> a[i];
  		if(a[i] % 2 == 0) {
  			evens.insert(a[i]);
  		}
  		every[a[i]]++;
  	}
    int evsplus = 0, evsminus = 0;
  	for(int x: evens) {
  		if(every.find(x-1) != every.end() && every[x-1] > 0) {
  			evsminus++;
  			every[x]--;
  			every[x-1]--;
  		} else if(every.find(x+1) != every.end()) {
  			evsplus++;
  			every[x+1]--;
  			every[x]--;
  		}
  	}
  	int odds = n - evens.size();
  	odds -= evsplus; odds -= evsminus;
  	int evsleft = evens.size() - evsplus - evsminus;

  	if(odds >= 0 && (odds % 2 ) == 0 && evsleft >= 0 && (evsleft % 2 == 0)) {
  		cout << "Yes\n";
  	} else {
  		cout << "No\n";
  	}



  }
return 0;
}
