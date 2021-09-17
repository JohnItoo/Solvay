// Problem: C. Deep Down Below
// Contest: Codeforces - Codeforces Round #740 (Div. 2, based on VK Cup 2021 -
// Final (Engine)) URL: https://codeforces.com/problemset/problem/1561/C Memory
// Limit: 512 MB Time Limit: 2000 ms
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

bool comp(ii a, ii b) {
  return a.x < b.x;
  // if (a.valmx != b.valmx) {
  // return a.valmx < b.valmx;
  // }
  // if (a.mxv != b.mxv) {
  // return a.mxv < b.mxv;
  // }
  // if (a.mxv == b.mxv && a.idv != b.idv) {
  // return a.idv > b.idv;
  // }
  //
  // return a.len > b.len;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  int mx = 1e5 + 1;
  while (tc--) {
    int caves;
    cin >> caves;
    vi gd(mx, -1);
    vector<int> cavesfreq(caves);
    vector<ii> wts(caves);

    vector<ii> act;
    int id = 0;

    forn(i, caves) {
      cin >> cavesfreq[i];

      int st = id;

      int valmx = -1;
      forn(j, cavesfreq[i]) {
        int curr;
        cin >> curr;
        gd[id++] = curr;
        valmx = max(valmx, curr - j);
      }

      act.pb({valmx, i});
      wts[i] = {st, id - 1};  // inclusive
    }
    sort(act.begin(), act.end(), comp);
    int dn = 0;
    int mx = 0;
    forn(i, caves) {
      int id = act[i].y;
      int sz = cavesfreq[id];
      // cout << id << " id " << wts[id].x << " " << wts[id].y << " ";

      int hid = 0;
      REP(j, wts[id].x, wts[id].y) {
        // cout << gd[j] << endl;
        int val = gd[j] + 1 - hid - dn;
        mx = max(mx, val);
        hid++;
      }
      dn += sz;
    }

    cout << mx << endl;
  }
  return 0;
}
