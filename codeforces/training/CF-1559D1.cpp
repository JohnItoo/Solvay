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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  vector<vector<int> > gpa(n + 5);
  vector<vi> gpb(n + 5);

  forn(i, a) {
    int u, v;
    cin >> u >> v;
    gpa[u].pb(v);
    gpa[v].pb(u);
  }

  forn(i, b) {
    int u, v;
    cin >> u >> v;
    gpb[u].pb(v);
    gpb[v].pb(u);
  }

  vector<vi> cta(10005, vector<int>(10005, 0));
  vector<vi> ctb(10005, vector<int>(10005, 0));

  set<int> vsa;
  vector<vi> compa;
  vector<vi> compb;
  int currcomp = 1;
  vi nodecompa(1005), nodecompb(1005);

  REP(i, 1, n) {
    if (vsa.find(i) != vsa.end()) continue;
    stack<int> dfs;
    dfs.push(i);
    vi mk;
    while (!dfs.empty()) {
      int tp = dfs.top();

      dfs.pop();
      if (vsa.find(tp) != vsa.end()) continue;
      // cout << tp << " tp\n";
      mk.pb(tp);
      nodecompa[tp] = currcomp;
      vsa.insert(tp);
      for (int ch : gpa[tp]) {
        if (vsa.find(ch) != vsa.end()) continue;
        // cout << ch << " " << vsa.size() << " not visited\n";
        dfs.push(ch);
      }
    }
    int sz = mk.size();

    forn(k, sz) {
      forn(j, sz) {
        if (j == k) continue;
        cta[mk[k]][mk[j]] = 1;
        cta[mk[j]][mk[k]] = 1;
      }
    }
    compa.pb(mk);
    currcomp++;
  }
  vsa.clear();
  currcomp = 1;

  REP(i, 1, n) {
    if (vsa.find(i) != vsa.end()) continue;
    stack<int> dfs;
    dfs.push(i);

    vi mk;
    while (!dfs.empty()) {
      int tp = dfs.top();
      dfs.pop();
      if (vsa.find(tp) != vsa.end()) continue;
      mk.pb(tp);
      nodecompb[tp] = currcomp;
      vsa.insert(tp);
      for (int ch : gpb[tp]) {
        dfs.push(ch);
      }
    }
    int sz = mk.size();

    forn(k, sz) {
      forn(j, sz) {
        if (j == k) continue;
        ctb[mk[k]][mk[j]] = 1;
        ctb[mk[j]][mk[k]] = 1;
      }
    }
    compb.pb(mk);
    currcomp++;
  }
  vii prs;

  REP(i, 1, n) {
    REP(j, i + 1, n) {  // pairs of nodes
      if (i == j) continue;

      if (cta[i][j] == 0 && ctb[i][j] == 0) {
        int compidai =
            nodecompa[i] - 1;  // id of the component node i is in for forest a
        int compidaj = nodecompa[j] - 1;  // id         "" j is in for forest a
        int compidbj = nodecompb[j] - 1;
        int compidbi = nodecompb[i] - 1;
        bool can = true;

        for (int k = 0; k < compa[compidai].size();
             k++) {  // all the nodes in this component
          forn(l, compa[compidaj].size()) {
            // if (k == l && compidai == compidaj) continue;
            if (compa[compidai][k] == compa[compidaj][l]) continue;
            // cout << " " << compidai << " " << compidaj << " " << l << endl;
            cout << compa[compidai][k] << " " << compa[compidaj][l] << endl;
            if (cta[compa[compidai][k]][compa[compidaj][l]] == 0 &&
                cta[compa[compidaj][l]][compa[compidai][k]] == 0) {
              cta[compa[compidai][k]][compa[compidaj][l]] = 1;
              cta[compa[compidaj][l]][compa[compidai][k]] = 1;
              cout << "ent\n";
            } else {
              can = false;
              cout << "brk\n";

              break;
            }
          }
          if (!can) break;
        }
        cout << "ode\n";

        for (int k = 0; k < compb[compidbi].size(); k++) {
          forn(l, compb[compidbj].size()) {
            if (!can) break;
            // if (k == l && compidbi == compidbj) continue;
            if (compb[compidbi][k] == compb[compidbj][l]) continue;

            if (ctb[compb[compidbi][k]][compb[compidbj][l]] == 0 &&
                ctb[compb[compidbj][l]][compb[compidbi][k]] == 0) {
              ctb[compb[compidbi][k]][compb[compidbj][l]] = 1;
              ctb[compb[compidbj][l]][compb[compidbi][k]] = 1;

            } else {
              can = false;
              break;
            }
          }
          if (!can) break;
        }

        if (can) {
          prs.pb({i, j});
        }
      }
    }
  }

  cout << prs.size() << endl;
  for (auto pr : prs) {
    cout << pr.x << " " << pr.y << endl;
  }

  return 0;
}
