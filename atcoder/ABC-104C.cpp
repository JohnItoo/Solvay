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
    int d,g; cin >> d >> g;
    g /= 100;
    vii a(d);
    vi nums(d);
    forn(i, d) {
    	int p, c; cin >> p >> c;
    	c /= 100;
    	a[i] = mp(p,c);
    	nums[i] = i+1;
    }
    
    int ans = 1e9+8;
    
    do {
    	int curr = 0;
    	int tot = 0;
    	forn(i, d) {
    		int p = a[nums[i]-1].first;
    		int c = a[nums[i]-1].second;
    
    		int act = p * nums[i];
    		if(curr + act + c < g) {
    			curr += act;
    			tot += p;
    			curr += c;
    		} else {
    			if(act + curr >= g) {
    				int ct = g - curr;
    			ct = (ct+nums[i]-1)/(nums[i]);
    			ct = min(ct, p);
    			tot += ct;
    			curr = g;
    			} else {
    				tot += p;
    				curr = g;
    			}
    			
    		}
           if(curr >= g) break;
    	}

    	ans = min(tot, ans);

    }while(next_permutation(nums.begin(), nums.end()));
    
    cout << ans << endl;
    return 0;
}
