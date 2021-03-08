// Problem: B. Planet Lapituletti
// Contest: Codeforces - Codeforces Round #705 (Div. 2)
// URL: https://codeforces.com/contest/1493/problem/B
// Memory Limit: 256 MB
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int hmax, mmax;
    cin >> hmax >> mmax;
    string s;
    cin >> s;
    string hour = s.substr(0, 2);
    string min = s.substr(3, 2);
    char mirr[] = {'0', '1', '2', '5', '8'};
    map<char, char> mirrormap;
    forn(i, 5) {
      if (mirr[i] == '2') {
        mirrormap['2'] = '5';
      } else if (mirr[i] == '5') {
        mirrormap['5'] = '2';
      } else {
        mirrormap[mirr[i]] = mirr[i];
      }
    }
    vector<string> times;
    forn(i, 5) {
      forn(j, 5) {
        string curr = "";
        curr.pb(mirr[i]);
        curr.pb(mirr[j]);
        times.pb(curr);
      }
    }

    string hmaxstring = to_string(hmax - 1);
    string mintmaxstring = to_string(mmax - 1);
    if (hmaxstring.length() == 1) hmaxstring = "0" + hmaxstring;
    if (mintmaxstring.length() == 1) mintmaxstring = "0" + mintmaxstring;
    bool fd = false;
    string hourres = "", minres = "";
    forn(i, times.size()) {
      forn(j, times.size()) {
        string mhour = times[i];
        string minute = times[j];
        string convhour = "";
        convhour.pb(mirrormap[minute[1]]);
        convhour.pb(mirrormap[minute[0]]);
        string convmin = "";
        convmin.pb(mirrormap[mhour[1]]);
        convmin.pb(mirrormap[mhour[0]]);

        int mhourint = stoi(mhour), minuteint = stoi(minute),
            convhint = stoi(convhour), convminint = stoi(convmin),
            hmaxint = stoi(hmaxstring), mmaxint = stoi(mintmaxstring);
        if ((mhourint < stoi(hour)) ||
            (mhourint == stoi(hour) && minuteint < stoi(min)))
          continue;

        if (mhourint <= hmaxint && convhint <= hmaxint &&
            convminint <= mmaxint && minuteint <= mmaxint) {
          fd = true;
          hourres = mhour;
          minres = minute;
          break;
        }
      }
      if (fd) break;
    }
    if (!fd) {
      cout << "00:00\n";
    } else {
      cout << hourres << ":" << minres << "\n";
    }
  }
  return 0;
}
