// Problem: Sliding Median
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1076
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
  int n, k;
  cin >> n >> k;
  vi a(n);
  forn(i, n) cin >> a[i];

  int i = 0;
  int ct = 0;
  multiset<int> leftMax; multiset<int> rightMin;

  auto balance = [&] {
    while (rightMin.size() > leftMax.size() ||
           leftMax.size() - rightMin.size() > 1) {
      if (leftMax.size() < rightMin.size()) {
        int tp = *rightMin.begin();
        auto it = rightMin.find(tp);
        rightMin.erase(it);
        leftMax.insert(tp);
      } else {
        auto it = leftMax.rbegin();
        int tp = *it;
        auto jt = leftMax.find(tp);
        
        leftMax.erase(jt);
        rightMin.insert(tp);
      }
    }
  };

  while (i < n && ct < k) {
    auto it = leftMax.rbegin();

    if (leftMax.size() > 0 && a[i] > *it) {
      rightMin.insert(a[i]);
    } else {
      leftMax.insert(a[i]);
    }
    i++;
    ct++;
    balance();
  }

  int j = 0;
  auto it = leftMax.rbegin();
  
 auto speak = [&] {
 	
 	for(auto val : leftMax) {
 		cout << val << " ";
 	}
 	cout << " - ";
 	for(auto val : rightMin) {
 		cout << val << " ";
 	}
 	cout << endl;
 };
 cout << *it << " ";
 //speak();
  while (i < n) {
  //	cout << a[i] << " i " << i << endl;
    if (rightMin.find(a[j]) != rightMin.end()) {
      rightMin.erase(a[j]);
    } else {
      leftMax.erase(a[j]);
    }
    
    j++;
    balance();
   // speak();
    auto it = leftMax.rbegin();

    if (leftMax.size() > 0 && a[i] > *it) {
      rightMin.insert(a[i]);
    } else {
      leftMax.insert(a[i]);
    }
    i++;
    balance();
    it = leftMax.rbegin();

   cout << *it << " ";
 // speak();
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  // cin >> tc;
  int count = 1;
  while (tc--) {
    // cout << "Case #" << count << ": "; //CODEJAM/KICKSTART
    count++;
    solve();
  }
  return 0;
}
