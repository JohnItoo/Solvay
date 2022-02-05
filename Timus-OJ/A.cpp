// Problem: A. Meximum Array
// Contest: Codeforces - Codeforces Round #767 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1628/A
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

void solve() {
  int n;
  cin >> n;
  map<int, int> fq;
  vi vc;
  forn(i, n) {
    int x;
    cin >> x;
    vc.pb(x);
    fq[x]++;
  }
  vi res;
  int i = 0;
  while (i < vc.size()) {

    set<int> unq;
    map<int, int> mpq = fq;
    int mx = fq.rbegin()->x;

    bool good = false;
    
 
    for (; i < vc.size(); i++) {

      int hr = vc[i];

      unq.insert(hr);
     
      int tm = fq[hr];
      if(tm == 1) {
      	fq.erase(hr);
      } else {
      	fq[hr]--;
      }
      mpq.erase(hr);
    
      if (mx == *unq.rbegin() && unq.size() == mx + 1) {
        res.pb(mx + 1);
        good = true;
        ++i;
        break;
        
      }
      int distance = mx - *unq.rbegin();
      
      if(*unq.rbegin() + 1 == unq.size() && distance != mpq.size()) {
      	res.pb(*unq.rbegin() + 1);
      	good = true;
      	++i;
      	break;
      }
    }

    if (!good) {
      int k = 0;
      for (auto it = unq.begin(); it != unq.end(); ++it) {
        if (*it != k) {
          res.pb(k);
          good = false;
          break;
        }
        k++;
      }
    }
 //   cout << i << "  iii \n";
  }
  cout << res.size() <<endl;
  for (int val : res) cout << val << " ";
  cout << endl;
 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  int count = 1;
  while (tc--) {
    // cout << "Case #" << count << ": "; //CODEJAM/KICKSTART
    count++;
    solve();
  }
  return 0;
}
