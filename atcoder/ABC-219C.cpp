// Problem: C - Neo-lexicographic Ordering
// Contest: AtCoder - Sciseed Programming Contest 2021（AtCoder Beginner Contest
// 219） URL: https://atcoder.jp/contests/abc219/tasks/abc219_c Memory Limit:
// 1024 MB Time Limit: 2000 ms
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

map<char, int> ord;

bool slesst(string s, string t) {
  int n = s.size();
  int m = t.size();
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (s[i] == t[j]) {
      i++;
      j++;
    } else {
      if (ord[s[i]] < ord[t[j]]) {
        return true;
      } else {
        return false;
      }
    }
  }
  if (j < m) {  // j >= m t is exhausted so t is less
    return true;
  } else {
    return false;
  }
}

vector<string> merge(vector<string> left, vector<string> rt) {
  int n = left.size();
  int m = rt.size();
  vector<string> res(n + m);
  int i = 0, k = 0, j = 0;
  while (i < n || j < m) {
    if (j == m || (i < n && slesst(left[i], rt[j]))) {
      res[k++] = left[i++];
    } else {
      res[k++] = rt[j++];
    }
  }
  return res;
}
vector<string> dort(vector<string> A) {
  int n = A.size();
  if (n < 2) return A;
  int mid = n / 2;
  vector<string> left, rt;
  for (int i = 0; i < mid; i++) {
    left.push_back(A[i]);
  }
  for (int i = mid; i < n; i++) {
    rt.push_back(A[i]);
  }
  left = dort(left);
  rt = dort(rt);
  return merge(left, rt);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;

  REP(i, 1, s.size()) { ord[s[i - 1]] = i; }
  int n;
  cin >> n;
  vector<string> vs(n);
  forn(i, n) { cin >> vs[i]; }
  vector<string> res = dort(vs);
  for (string hr : res) cout << hr << "\n";
  return 0;
}
