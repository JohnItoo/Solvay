// Problem: C. Water the Trees
// Contest: Codeforces - Educational Codeforces Round 126 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1661/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

struct Ob {
  vector<ll> odds;
  vector<ll> evs;
  ll sumodds = 0;
  ll sumevs = 0;
};

Ob get(vector<ll> h, ll mx) {
  int n = h.size();
  Ob ob;
  vector<ll> odds;
  vector<ll> evs;
  ll sumodds = 0;
  ll sumevs = 0;
  forn(i, n) {
    if (h[i] == mx) continue;
    ll diff = mx - h[i];
    if (diff & 1) {
      odds.pb(diff);
      sumodds += diff;
    } else {
      evs.pb(diff);
      sumevs += diff;
    }
  }
  ob.odds = odds;
  ob.evs = evs;
  ob.sumodds = sumodds;
  ob.sumevs = sumevs;
  return ob;
}

void solve() {
  int n;
  cin >> n;
  ll mxx = -1e10 - 3;
  vector<ll> h;
  forn(i, n) {
    ll x;
    cin >> x;
    mxx = max(x, mxx);
    h.pb(x);
  }
  ll res = 1e17;
  for (ll mx = mxx; mx <= mxx + 1; mx++) {
    Ob ob = get(h, mx);
    vector<ll> odds = ob.odds;
    vector<ll> evs = ob.evs;
    ll sumodds = ob.sumodds;
    ll sumevs = ob.sumevs;

    if (odds.size() == 0 && evs.size() == 0) {
      cout << 0 << endl;
      return;
    }
    ll remodds = sumodds - odds.size();
    ll reqgrowth = remodds + sumevs;

    ll left = 0;
    ll right = 1e17;
    ll ans = -1;

    while (left < right) {
      ll mid = (right + left) / 2;
      ll eday = mid / 2LL;
      ll oday = mid - eday;

      if (oday < odds.size()) {
        left = mid + 1;
      } else {
        oday -= odds.size();
        ll totalval = oday + (2 * eday);
        if (totalval >= reqgrowth) {
          right = mid;
          ans = mid;
        } else {
          left = mid + 1;
        }
      }
    }
    res = min(ans, res);
  }
  cout << res <<endl;

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
