// Problem: Reversort
// Contest: Google Coding Competitions - Qualification Round 2021 - Code Jam
// 2021 URL:
// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d0a5c
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
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
    int count = 1;
    while (tc--) {
        cout << "Case #" << count << ": ";
        count++;
        int n;
        cin >> n;
        vi a(n);
        vi sor(n);
        forn(i, n) {
            cin >> a[i];
            sor[i] = a[i];
        }
        sort(sor.begin(), sor.end());
        int cost = 0;
        REP(i, 0, n - 2) {
            if (a[i] == sor[i]) {
                // cout << "here\n";
                cost++;
            } else {
                int j = 0;
                while (j < n && a[j] != sor[i]) j++;
                //  cout << i << " " << j << " this is j\n";
                int curr = ((max(j, i) - min(j, i)) + 1);
                cost += curr;
                // cout << j << " " << i << " " << curr << endl;
                reverse(a.begin() + min(i, j), a.begin() + max(i, j) + 1);
                // forn(i,n) cout << a[i] << " ";
                // cout << endl;
            }
        }
        cout << cost << "\n";
    }
    return 0;
}