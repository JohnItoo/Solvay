#include <bits/stdc++.h>
using namespace std;
#define _CRT_SECURE_NO_DEPRECATE

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define REP(i, a, b) \
    for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define forn(i, n) \
    for (int i = 0; i < (n); i++)
#define TRvi(c, it) \
    for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
    for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
    for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000 // 2 billion
// If you need to recall how to use memset:
#define MEMSET_INF 127     // about 2B
#define MEMSET_HALF_INF 63 // about 1B
//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); // useful to clear array of integers

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    forn(i, n) cin >> a[i];

    map<int, ll> fq;
    forn(i, q)
    {
        int x, y;
        cin >> x >> y;
        fq[x]++;
        if (fq.find(y + 1) != fq.end())
        {
            fq[y + 1]--;
        }
        else
        {
            fq[y + 1] = -1;
        }
    }
    vector<ll> vll;
    ll prev = 0;
    for (auto kk : fq)
    {
        
        prev += kk.second;
        int i = kk.first;
        if (prev == 0)
            break;
        vll.pb(prev);
        i += 1;
        while (fq.find(i) == fq.end())
        {
            vll.pb(prev);
            i++;
        }
    }
    sort(vll.rbegin(), vll.rend());
    sort(a.rbegin(), a.rend());

    ll ans = 0;
    forn(i, vll.size())
    {
        ans += (a[i] * vll[i]);
    }

    cout << ans << endl;

    return 0;
}