//============================================================================
// Name        : template.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
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
// 	ios::sync_with_stdio(false);
//  cin.tie(0);
//  string s; cin >> s;
//  int rs = 0;
//  int mx = 0;
//  forn(i, s.length()) {
//  	if(s[i] == 'R') {
//  		rs++;
//  		mx = max(rs, mx);
//  	} else {
//  		mx = max(rs, mx);
//  		rs = 0;
//  	}
//  }
//  cout  << mx << "\n";
// return 0;
// }



// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	int n = 0; cin >> n;
// 	vector<ll> l(n + 1);
// 	REP(i, 1, n) {
// 		cin >> l[i];
// 	}

// 	map<string, int> mp;

// 	int ans = 0;
// 	for (int i = 1; i + 2 <= n; i++) {
// 		for (int j = i + 1; j + 1 <= n; j++) {
// 			for (int k = j + 1; k <= n; k++) {
// 				if (l[i] != l[j] && l[j] != l[k] && l[i] != l[k] ) {
// 					// vector<ll> bs;
// 					// bs.pb(l[i]); bs.pb(l[j]); bs.pb(l[k]);

// 					// if (st.count(make_tuple(bs[0], bs[1], bs[2])) == 0) {
// 					//&&
// 					string s;
// 					char ii = (char) l[i] + '0';
// 					char jj = (char) l[j] + '0';
// 					char kk = (char) l[k] + '0';
// 					s.pb(ii);
// 					s.pb(jj);
// 					s.pb(kk);
// 					sort(s.begin(), s.end());
// 					// cout << s << "\n";
// 					if (((s[0] - '0' + s[1] - '0') > s[2] - '0')) {
// 						ans++;
// 					}

// 					// }

// 				}
// 			}
// 		}
// 	}
// 	cout << ans << "\n";
// 	return 0;
// }


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll x, k, d;
	cin >> x >> k >> d;

	if (x < 0) {
		ll f =    -x;
		if ( k * d < f) {
			cout << abs(x + (k * d)) << "\n";
		} else {
			ll div = f / d;
			ll curr = x + (d * div);
			k -= div;
			if (k & 1) {
				cout << min(abs(curr - d), abs(curr + d)) << "\n";
			} else {
				if (k != 0) cout << min( min(abs(curr + (2 * d)), abs(curr)), abs(curr - (2 * d)));
				else cout << abs(curr) << "\n";
			}
		}

	} else {
		ll f = x - 0; //steps to 0;
		if (k * d < f) {
			cout << f - (k * d) << "\n";
		} else {
			ll div =  x / d;
			ll rem = x - (div * d);
			k -= div;
			if (k & 1) {
				cout << min(abs(rem + d), abs(rem - d)) << "\n";
			} else {
				if (k == 0) cout << rem << "\n";
				else {
					cout << min(min(abs(rem - (2 * d)), abs(rem)), abs(rem + (2 * d)));
				}

			}
		}
	}
	return 0;
}
