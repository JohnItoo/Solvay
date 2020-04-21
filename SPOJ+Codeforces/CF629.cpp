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
//     int tc; cin >> tc;
//     cout << "\n";
//     while(tc--) {
//         int a, y;
//         cin >> a >> y;
//         if (a ==0 || y == 0) { cout  << 0 <<"\n"; continue;}
//         if(a % y==0) {cout << 0 << "\n"; continue;}
//         else {
//  int ans = a / y;
//         int sol =  (y * (ans + 1)) - a;
//         cout << sol << "\n";
//         }
    
// }
// return 0;

// }

// vector<string> res;
// void bk(vector<string> vc, string s, int a, int b, int dn[], int ct, int k) {
//    if(a==0 && b ==0)  {
//     //    cout << s << "\n";
//        res.pb(s);
//       return;
//     }
   
//    for(int i = 0; i<vc.size(); ++i) {
//        if(dn[i] == 1) continue;
//        if(vc[i] == "a") a -= 1; 
//        if(vc[i] == "b") b -= 1;
//        dn[i] = 1;
//        bk( vc, s+vc[i], a, b, dn, ct, k);
//        dn[i] = 0;
//        if(vc[i] == "a") a += 1; 
//        if(vc[i] == "b") b += 1;

//    }
//    return;
// }

// int main() {
//     int tc; cin >> tc;
//     while(tc--) {
//         res.clear();
//         int n , k; cin >> n >>k;
//         vector<string> v; int ar[n]; 
//         forn(i,n-2) {v.pb("a");}
//         v.pb("b"); v.pb("b");
//         bk(v, "", n-2, 2, ar, 0, k);
//         sort( res.begin(), res.end() );
// res.erase( unique( res.begin(), res.end() ), res.end() );
//         cout << res[k-1] << "\n";
//     }
//     return 0;
// }



// int main() {
//     int tc;
//     while(tc--) {
//         stack<int> s;
//         ll n; llt;
//         cin >> n >> t;
//         ll re =t;
//         while(re) {
//             s.push(re%10);
//             re/=10;
//         }
//         ll x; ll y;
//         int curr = s.pop();
//         if(curr == 0){ x *= 10 + curr;  y*= 10 + curr;}
//         else if(curr == 1) {
//             if(max((x * 10) + 1 , (y*10) + 0) < max((y*10)+1, (x*10))) {
//                 x =  (x*10) + 1;
//                 y*=10;
//             } else {
//                 y = (y*10) +1;
//                 x*=10;
//             }
//         } else {
//             ll f = (x * 10) + 2;
//             ll g = (x * 10) + 1;
//             ll h = x * 10;

//             ll q =  (y * 10) + 2;
//             ll w = (y * 10) + 1;
//             ll e = (y * 10);

//          if(max(f, e ) > max(f))
//         }

//     }
// }
 
 int main() {
     int tc;
     cin >> tc;

     while(tc--) {
         ll n, k;
        cin >> n >>k;

        ll i = 1; ll as; ll fr;
        while(true) {
            
            ll sum = (i*(i+1)/2);
            if(k >= sum - i - 1 && k < sum + 1) {
          cout << "This is sum" << sum << " i : " << i;

               as = (2*i -1) - k;
               fr = i;
               break;
            }
            i++;
        }
    
        int b = fr;
        string s = "";
        for(ll j = 1; j<=n; j++) {
           if(n-j == b) {
               s+= "b"; 
               b = b -as - 1;
               continue;
           }
           s+="a";
        }
        cout << fr << " " << b << " " <<  s << "\n";
     }
 }

