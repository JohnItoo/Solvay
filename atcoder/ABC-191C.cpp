//============================================================================
// Name        : template.cpp
// Author      :
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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    forn(i, h) cin >> s[i];

    int i = 1;
    int j = 1;
    while (i < h && j < w) {
        if (s[i][j] == '#')
            break;
        else {
            j++;
            if (j == w) {
                i++;
                j = 1;
            }
        }
    }
    int str = i;
    int stc = j;
    int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int ans = 0;
    bool fd = false;
    int ch = -1;

    while (!fd) {
        bool change = false;
        forn(k, 4) {
            if (ch == k) continue;
            if ((ch == 1 && i == 3) || (ch == 3 && i == 1)) continue;
            if ((ch == 0 && i == 2) || (ch == 2 && i == 0)) continue;
            int nr = i + mv[k][0];
            int nc = j + mv[k][1];
            if (nr < h && nc < w && s[nr][nc] == '#') {
                ch = k;
                change = true;
                ans++;
                i = nr;
                j = nc;
                break;
            }
        }
        if(!change) break;
        while ((i + mv[ch][0]) < h && (j + mv[ch][0]) < w &&
               s[(i + mv[ch][0])][(j + mv[ch][0])] == '#') {
            i += mv[ch][0];
            j += mv[ch][0];
            if (i == str && j == stc) {
                fd = true;
                break;
            }
        }
    }
    if (ans == 0)
        cout << 1 << endl;
    else
        cout << ans << endl;
    return 0;
}
