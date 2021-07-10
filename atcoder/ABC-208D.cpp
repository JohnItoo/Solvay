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

vector<ll> kthExcluded(vector<ll> a, vector<ll> queries) {
    vector<ll> result;
    int n = a.size();
    int q = queries.size();

    vector<ll> prefix(n);

    ll last_element = a[0];
    prefix[0] = a[0] - 1;
    // 3 5 6 7
    // 2 3

    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + (a[i] - last_element - 1);
        last_element = a[i];
    }

    for (int i = 0; i < q; i++) {
        ll qi = queries[i];
        auto it = lower_bound(prefix.begin(), prefix.end(), qi);
        if (it != prefix.end()) {
            if (*it == qi) {
                result.push_back(a[it - prefix.begin()] - 1);
            } else {
                ll diff = *it - qi;
                ll element = a[it - prefix.begin()] - diff - 1;
                result.push_back(element);
            }
        } else {
            int idx = n - 1;
            ll diff = qi - prefix[n - 1];
            result.push_back(diff + a[n - 1]);
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    vector<ll> queries(q);
    forn(i, n) cin >> a[i];
    forn(i, q) cin >> queries[i];

    vector<ll> result = kthExcluded(a, queries);
    for (auto ans : result) cout << ans << endl;

    return 0;
}
