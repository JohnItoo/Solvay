// Problem: C. Interesting Story
// Contest: Codeforces - Codeforces Round #734 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1551/C
// Memory Limit: 256 MB
// Time Limit: 4000 ms
//
// Powered by CP Editor (https://cpeditor.org)

//============================================================================
// Name        : template.cpp
// Author      :   $%U%$
// Version     :
// Copyright   : Your copyright notice
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
bool cmp(ii a, ii b) {
  if (a.x * 2 > a.y && b.x * 2 > b.y) {
    return a.y > b.y;
  }
  if (a.x * 2 > a.y) {
    return true;
  }

  if (b.x * 2 > b.y) {
    return false;
  }

  // if (a.x == b.x) {
  // return a.y < b.y;
  // }
  //
  // return a.x > b.x;
  return a.y < b.y;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<vector<int> > val(5, vi(n, 0));
    vector<string> strings(n);
    vector<vector<ii> > st(5, vector<ii>(n));
    forn(i, n) {
      string s;
      cin >> s;
      strings[i] = s;
      forn(j, s.size()) {
        int id = s[j] - 'a';
        val[id][i]++;

        // st[id][i] = {st[id][i].x + 1, s.size()};
      }
    }

    forn(i, 5) {
      forn(j, n) {
        int sz = strings[j].size();
        st[i][j] = {val[i][j], sz};
        //  cout << st[i][j].x << "," << st[i][j].y << " ";
      }
      sort(st[i].begin(), st[i].end(), cmp);
      // forn(j, n) { cout << st[i][j].x << "," << st[i][j].y << " "; }
      // cout << endl;
    }
    int mx = 0;
    forn(i, 5) {
      //  sort(st[i].begin(), st[i].end(), cmp);
      int sm = 0;
      int curr = 0;
      int j = 0;
      int ent = 0;

      while (j <= n - 1) {
        if ((curr + st[i][j].x) * 2 <= sm + st[i][j].y) {
          j++;
          continue;
        }
        sm += st[i][j].y;
        curr += st[i][j].x;
        j++;
        ent++;
      }
      mx = max(mx, ent);
      // cout << "new\n";
    }
    cout << mx << endl;
  }
  return 0;
}
