#include <bits/stdc++.h>
using namespace std;
#define _CRT_SECURE_NO_DEPRECATE
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
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        int twos = 0, ones = 0;
        forn(i, n)
        {
            int curr;
            cin >> curr;
            if (curr == 2)
                twos++;
            else
                ones++;
        }
        int tot = (twos * 2) + ones;
        if ((tot % 2))
        {
            cout << "no\n";
        }
        else
        {
            int need = tot / 2;
            int tw = need / 2;
            int o = need - (2 * tw);
            if ((need % 2 == 0) || ones >= 1)
            {
                cout << "yes\n";
            }
            else
            {
                cout << "no\n";
            }
        }
    }
    return 0;
}