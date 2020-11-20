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

struct Use {
	ll x, y, z;
	Use(ll x, ll y, ll z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

bool comp(Use a, Use b) {
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

bool overlaps(Use a, Use b) {
	return (b.x < a.y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, w; cin >> n >> w;
	vector<Use> uses;
	forn(i, n) {
		ll s, t, p; cin >> s >> t >> p;
		Use use = Use(s, t , p);
		uses.pb(use);
	}
	sort(uses.begin(), uses.end(), comp);
	int i = 0;
	int j = 1;
	ll curr = uses[i].z;

	while (i < n && j < n && curr <= w) {
		Use a = uses[i];
		Use b = uses[j];
		if (overlaps(a, b)) {
			curr += b.z;
			j++;
		} else {
			while ( i < j && !overlaps(uses[i], uses[j])) {
				curr -= uses[i].z;
				i++;
			}
			if (i == j) j++;
		}
	}
	if (curr <= w) {
		if (i + 1 != j || uses[i].z <= w ) cout << "Yes\n";
		else cout << "No\n";
	}
	else {
       cout << "No\n";
	}

	return 0;
}
