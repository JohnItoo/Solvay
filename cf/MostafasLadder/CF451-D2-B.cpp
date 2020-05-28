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
// to_string(int)

string trUpp(string s) {

    transform(s.begin(), s.end(), s.begin(), ::toupper);
    return "";
}

int main() {
    int n; cin >> n;
    ll a[n];
    forn(i, n) cin >> a[i];
    int left = -1; int right = -1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1] && left == -1) {left = i;}
        if (left != -1 && a[i] < a[i + 1]) {
            right = i; break;
        }
    }

    if (left != -1 && right == -1) right = n - 1;
    int lf = left; int rt = right;
    if (left != -1 && right != -1) {
        REP(i, left, right) {
            if (right < left) break;
            ll templeft = a[left];
            a[left] = a[right];
            a[right] = templeft;
            left++; right--;
        }
    }
    if (lf == -1 && rt == -1) {
        lf = 0; rt = 0;
    }

    bool ans = true;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {ans = false; break;}
    }

    if (ans) {
        cout << "yes" << endl;
        cout << lf + 1 << " " << rt + 1;
    } else { cout << "no" << endl;}

    return 0;
}
