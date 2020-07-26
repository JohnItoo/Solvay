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

bool comp(ii a, ii b) {
  int asum = a.first + a.second;
  int bsum = b.first + b.second;
  // if (asum ==  bsum) return a.second > b.second;
  // return asum < bsum;
  if(a.second == b.second) return a.first < b.first;

  return a.second  < b.second;
}

void solve() {
  int n;
  cin >> n;
  vii pairs(n);
  forn(i, n) {
    int x = 0; int y = 0;
    cin >> x >> y;
    pairs[i] = mp(x, y);
  }

  sort(pairs.begin(), pairs.end(), comp);
  forn(i, pairs.size()) {
    cout << pairs[i].first << " " << pairs[i].second << "\n";
  }

  bool visited[n];
  memset(visited, false, sizeof visited);

  int mx = 0;
      ii beginning = mp(0,0);

  forn(i, n) {
    if (visited[i]) continue;

    ii start = pairs[i];
    ii beg = mp(start.first - start.second, start.first + start.second);

    int j = i + 1;
    bool found = false;
    bool dir = false;
    int target = 0;
    int currMax = start.second;
    while (j < n && !found) {
      if (!visited[j]) {
        if (beg.first == pairs[j].first || (beg.first == pairs[j].first + pairs[j].second )) {
          found = true;
          currMax += pairs[j].second;
          if (beg.first == pairs[j].first) {
            target = pairs[j].first - pairs[j].second;
            dir = false;
          } else {
            target = pairs[j].first;
            dir = true; // we cut the beggining to left and this continuation cuts to right to meet so we keep cutting to the right.
          }
        } else if (beg.second == pairs[j].first || (beg.second == pairs[j].first - pairs[j].second)) {
          found = true;
          currMax += pairs[j].second;
          if (beg.second == pairs[j].first) {
            target = pairs[j].first + pairs[j].second;
            dir = true;
          } else {
            target = pairs[j].first;
            dir = false;
          }
          cout << "found at j " <<  j << "\n";
        }
      }
      j++;
    }

    cout << "This is target : " << target << "\n";

    if (found) {
      while (j < n) {
        // if (!visited[j]) {
        int moves = dir ? pairs[j].first + pairs[j].second : pairs[j].first - pairs[j].second;

        if (dir) {
          if (target == pairs[j].first) {
            visited[j] = true;
            target = moves;
            currMax += pairs[j].second;
            // cout << "This is move " << moves << "\n";
            //        }
          }
        } else {
          if (target == moves) {
            visited[j] = true;
            target = pairs[j].first;
            currMax += pairs[j].second;
          }
        }
        j++;
      }
    }

    if(currMax > mx) {
      mx = currMax;
      beginning = start;

    }
    mx = max(mx, currMax);
  }

  cout << mx << " " << beginning.first << " "<< beginning.second << " \n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc = 0;
  cin >> tc;
  int ct = 1;
  while (tc--) {
    cout << "Case #" << ct << ": ";
    ct++;
    solve();
  }
  return 0;
}