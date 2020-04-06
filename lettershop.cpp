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
int n,m,mk[500004];
string t;
vector<pair<char, int> >  vc;

//THis just picks the right most guy.. Or not??

int search(int top, int bt, char p) {
    if(top > bt) {return -1;}
    int mid = top + (bt - top) /2 ;
    if(vc[mid].first = p && mk[vc[mid].second] != 2) {
       mk[vc[mid].second]  = 2;
       cout << "Found char " << p << " : " <<  vc[mid].second <<endl;
       return vc[mid].second;
    }
    if(vc[mid].first > p) {
        search(0, mid - 1, p);
    } else {
        search(mid+1, bt, p);
    }
}

void handle() {
    int ans = -1;
    int l = t.length();
    // forn(i, l) {
    //  ans = max(ans, search(0, l-1, t[i]));
    // }
    for(auto a :vc) {
        cout << a.first <<" " <<a.second;
    }
    cout << ans << endl;
}
int main() {
    cin >> n;
    string s;

    cin >> s;
    REP(i, 1,n) {
     cout << s[i-1] << " " << i <<endl;
      vc.push_back(mp(s[i-1], i));
    }  
    sort(vc.begin(), vc.end());

    cin >> m;
    
    while(m--) {
       cin >> t;
       handle();
       memset(mk, 0, sizeof mk);
    }

return 0;
}
