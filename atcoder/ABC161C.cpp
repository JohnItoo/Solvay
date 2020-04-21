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

// int main() {
//     int x,y,z;
//     cin >> x >> y >> z;
//     swap(x,y); swap(x,z); 
//     cout << x << " " << y << " " << z;
// return 0;
// }

// int main() {
//     int a ,b;
//     cin >> a >> b;
//     vi arr;
//     int sm;
//     forn(i,a) {
//         int x; cin >>x;
//      sm+=x;
//       arr.pb(x);
//     }
//     int ans = 0;
//     forn(i,a) {
//       int val = sm/(4*b) + (sm % (4 *b) != 0);
//       if(arr[i] < val) continue;
//       ans++;
//     }
//      if(ans >= b) cout << "Yes";
//      else cout << "No";
//     // cout << sol;
//     return 0;
// }

// int main() {
//     ll n, k;
//     cin >> n >> k;
//     ll ans = 0;
//     if(n > k) {
//        ll f = (n - (n/k) * k );
//         ans = min(f, abs(f-k));
//     }
//     if(n < k) ans = min(k-n, n);
//     cout << ans;
//     return 0;
// }

bool isT(ll n) {
    ll reg = n;
    ll prev = -1;
    bool ans = true;
    if(n > 0 && n <=12) return true;
   while(reg>0) {
       ll curr = reg%10;
       if(prev != -1) {
        //    cout << curr << " curr" <<  " " << prev << "\n";
         if(abs(curr-prev) > 1) {
           ans = false; 
         } 
       }
       prev= curr;
      reg/=10;
      if(!ans) break;

   }
        //   cout << "This is one" << reg <<  " " << prev <<"\n";

//    if(ans && reg < 10) {
//     //    cout << "This is reg" << reg <<  " " << prev <<"\n";
//        ans = abs(reg-prev) <= 1;
//    }
//    cout << n << " " << ans << "\n";
   return ans;
}

int main() {
    ll k; cin >> k;

    ll ct = 0; ll  i = 1; ll lst = -1;
    while(ct < k) {
        // cout << "This is i "<< i<< "\n";
        if(isT(i)) {
        
         lst = i;
         ct++;
        }
        i++;
    }
    cout << lst;

    //cout << isT(k);
}
