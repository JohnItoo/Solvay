// Problem: E - Amusement Park
// Contest: AtCoder - AtCoder Beginner Contest 216
// URL: https://atcoder.jp/contests/abc216/tasks/abc216_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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

ll sm(ll a, ll d, ll n) { return (n * (2 * a + ((n - 1) * d))) / 2; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> vcs;
  forn(i, n) {
    ll x;
    cin >> x;
    vcs.pb(x);
  }
  sort(vcs.begin(), vcs.end(), greater<>());
  vcs.pb(0);
  ll sum = 0;

  forn(i, n) {
    ll diff = vcs[i] - vcs[i + 1];
    ll ct = 1LL * diff * (i + 1);

    if (ct <= k) {
      k -= ct;
      sum += sm(vcs[i], -1LL, diff) * (i + 1);
    } else {
      ll d = k / (i + 1);
      ll md = k % (i + 1);
      sum += sm(vcs[i], -1LL, d) * (i + 1);
      sum += (vcs[i] - d) * md;
      k = 0;
    }
  }
  cout << sum << endl;

  return 0;
}
