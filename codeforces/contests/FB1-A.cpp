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
#include <cmath>
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


void solve() {
	int n, k, w;
	cin >> n >> k >> w;
	vector<ll> l(n);

	forn(i, k)  cin >> l[i];
	

	ll al,bl,cl,dl;
	cin >> al >> bl >> cl >> dl;

	vector<ll> h(n);
	forn(i,k) cin >> h[i];

	ll ah,bh,ch,dh;
	cin >> ah >> bh >> ch >> dh;


	REP( i , k , n-1) {
       l[i] = ((al * l[i-2] + bl * l[i-1] + cl) % dl) + 1;
       h[i] = ((ah * h[i-2] + bh * h[i-1] + ch) % dh) + 1;
	}

	vector<pair<pair<ll, ll>, pair<ll, ll> > > rooms;

	ll p = 1;

	forn(i,n) {
		pair<ll,ll> st = mp(l[i], 0);
		pair<ll, ll> ed = mp(l[i]+w, h);
		pair<pair<ll, ll>, pair<ll, ll> > qr = mp(st,ed);
		rooms.pb(qr);
	}

	forn(i, n) {
        
		ll side1 = h[0];
		ll width = rooms[i].second.first - rooms[0].first.first;
		ll side2 =  width;
		ll side3 = h[i];
		ll side4 = width;
		if(side3 != side1) {
			ll diff = abs(side1- side3);
			ll side4sq = diff * diff + side2*side2;
			side4 = pow(side4sq, 0.5);
		}
		ll currp = side1 + side2 + side3 + side4;

		p *= currp;
		cout << p << "\n";
		p %= 1000000007;
	}

	cout << p << "\n";

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc = 0;
	cin >> tc;
	int ct = 1;
	while (tc--) {
		cout << "Case #" << ct << ": \n";
		ct++;
		solve();
	}
	return 0;
}

